#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> 
            (x % 2 == 0 || (y % 2 == 0 && y <= 4 * (x / 2) && y >= 2 * (x / 2)));
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int x_local = x;
    unsigned int y_local = y;
    unsigned int x_div_2 = 0;
    unsigned int temp_x = x_local;
    
    /*@
        loop invariant 1 <= x_local <= 100;
        loop invariant 1 <= y_local <= 100;
        loop invariant 0 <= x_div_2;
        loop invariant 0 <= temp_x;
        loop invariant temp_x + 2 * x_div_2 == x_local;
        loop assigns temp_x, x_div_2;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
        x_div_2 += 1;
    }
    
    unsigned int x_mod_2 = (temp_x == 1) ? 1 : 0;
    
    unsigned int y_div_2 = 0;
    unsigned int temp_y = y_local;
    
    /*@
        loop invariant 1 <= x_local <= 100;
        loop invariant 1 <= y_local <= 100;
        loop invariant 0 <= y_div_2;
        loop invariant 0 <= temp_y;
        loop invariant temp_y + 2 * y_div_2 == y_local;
        loop assigns temp_y, y_div_2;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        y_div_2 += 1;
    }
    
    unsigned int y_mod_2 = (temp_y == 1) ? 1 : 0;
    
    bool within_range = false;
    
    if (x_mod_2 == 0 || (y_mod_2 == 0 && y_local <= 4 * x_div_2 && y_local >= 2 * x_div_2))
    {
        within_range = true;
    }
    
    //@ assert x_div_2 == x_local / 2;
    //@ assert y_div_2 == y_local / 2;
    //@ assert x_mod_2 == x_local % 2;
    //@ assert y_mod_2 == y_local % 2;
    
    return (x_mod_2 == 0) || within_range;
}

int main(void)
{
    return 0;
}

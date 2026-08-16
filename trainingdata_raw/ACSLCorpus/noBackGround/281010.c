#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100 && 1 <= (y) <= 100);
    ensures ((\result) == ((y) % 2 == 0 && (x) <= (y)));
    assigns \nothing;
*/
bool func(int x, int y)
{
    bool even_flag;
    int temp_y;
    
    //@ assert (1 <= (x) <= 100 && 1 <= (y) <= 100);
    
    temp_y = y;
    even_flag = false;
    
    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        //@ assert temp_y % 2 == y % 2;
        temp_y -= 2;
    }
    
    //@ assert temp_y % 2 == y % 2;
    even_flag = (temp_y == 0);
    
    //@ assert even_flag == (y % 2 == 0);
    
    return even_flag && x <= y;
}

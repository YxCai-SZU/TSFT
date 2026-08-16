#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) / 3) * ((x) / 3) * ((x) / 3);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t x_div_3;
    int64_t temp_x;
    int64_t count;
    
    x_div_3 = 0;
    temp_x = x;
    count = 0;
    
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant temp_x >= 0;
        loop invariant x == temp_x + 3 * count;
        loop invariant count >= 0;
        loop invariant count <= ((x) / 3);
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        temp_x -= 3;
        count += 1;
    }
    
    x_div_3 = count;
    
    //@ assert x_div_3 >= 0 && x_div_3 <= 33;
    //@ assert x_div_3 * x_div_3 <= 1089;
    //@ assert x_div_3 * x_div_3 * x_div_3 <= 35937;
    
    return x_div_3 * x_div_3 * x_div_3;
}

int main()
{
    return 0;
}

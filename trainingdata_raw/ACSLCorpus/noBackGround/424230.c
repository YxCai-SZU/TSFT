#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) - ((x) / 500) * 500) / 5) * 5);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t x_500 = 0;
    int64_t temp_x = x;
    int64_t x_5 = 0;
    
    /*@
        loop invariant 0 <= x_500;
        loop invariant x_500 <= x / 500;
        loop invariant temp_x == x - x_500 * 500;
        loop invariant 0 <= temp_x;
        loop assigns x_500, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        x_500 += 1;
        temp_x -= 500;
    }
    
    /*@
        loop invariant 0 <= x_500;
        loop invariant x_500 <= x / 500;
        loop invariant 0 <= x_5;
        loop invariant x_5 <= (x - x_500 * 500) / 5;
        loop invariant temp_x == x - x_500 * 500 - x_5 * 5;
        loop invariant 0 <= temp_x;
        loop assigns x_5, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        x_5 += 1;
        temp_x -= 5;
    }
    
    //@ assert x_500 * 1000 + x_5 * 5 == (((x) / 500) * 1000 + (((x) - ((x) / 500) * 500) / 5) * 5);
    return x_500 * 1000 + x_5 * 5;
}

int main()
{
    return 0;
}

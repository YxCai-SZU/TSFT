#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((((x)) / 500) * 1000) + (((((x)) % 500) / 5) * 5));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t res = 0;
    int64_t temp_x = x;
    int64_t count_500 = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant count_500 * 500 + temp_x == x;
        loop invariant 0 <= count_500 <= x / 500;
        loop assigns temp_x, count_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        count_500 += 1;
    }
    //@ assert temp_x == x % 500;
    
    res += count_500 * 1000;
    
    int64_t count_5 = 0;
    /*@
        loop invariant 0 <= temp_x <= x % 500;
        loop invariant count_5 * 5 + temp_x == x % 500;
        loop invariant 0 <= count_5 <= (x % 500) / 5;
        loop assigns temp_x, count_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        count_5 += 1;
    }
    //@ assert temp_x == (x % 500) % 5;
    
    res += count_5 * 5;
    
    //@ assert res == (((((x)) / 500) * 1000) + (((((x)) % 500) / 5) * 5));
    return res;
}

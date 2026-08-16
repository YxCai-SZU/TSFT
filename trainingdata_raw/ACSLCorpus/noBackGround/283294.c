#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures \result >= 0;
    ensures \result == (x / 500) * 1000 + (x % 500) / 5 * 5;
*/
int64_t func(int64_t x)
{
    int64_t original_x = x;
    int64_t sum = 0;
    int64_t div_500 = 0;
    int64_t temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant div_500 >= 0;
        loop invariant temp_x == original_x - 500 * div_500;
        loop invariant 0 <= original_x <= 1000000000;
        loop assigns temp_x, div_500;
    */
    while (temp_x >= 500)
    {
        temp_x -= 500;
        div_500 += 1;
    }
    
    sum += div_500 * 1000;
    x = temp_x;
    
    int64_t div_5 = 0;
    temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant div_5 >= 0;
        loop invariant temp_x == x - 5 * div_5;
        loop invariant 0 <= x <= 1000000000;
        loop assigns temp_x, div_5;
    */
    while (temp_x >= 5)
    {
        temp_x -= 5;
        div_5 += 1;
    }
    
    sum += div_5 * 5;
    
    //@ assert sum >= 0;
    //@ assert sum == (original_x / 500) * 1000 + (original_x % 500) / 5 * 5;
    
    return sum;
}

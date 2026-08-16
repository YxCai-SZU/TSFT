#include <stdint.h>

/*@
    predicate is_in_range(integer x) = 0 <= x <= 1000000000;
    
    logic integer total_n(integer x) = x / 500;
    logic integer total_m(integer x, integer n) = (x - n * 500) / 5;
    
    logic integer expected_result(integer x) = 
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires is_in_range(x);
    ensures \result == expected_result(x);
*/
int64_t func(int64_t x)
{
    int64_t n = 0;
    int64_t m = 0;
    int64_t temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= n <= total_n(x);
        loop invariant temp_x == x - n * 500;
        loop assigns temp_x, n;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        n += 1;
    }
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= n <= total_n(x);
        loop invariant 0 <= m <= total_m(x, n);
        loop invariant temp_x == x - n * 500 - m * 5;
        loop assigns temp_x, m;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        m += 1;
    }
    
    //@ assert n * 1000 + m * 5 == expected_result(x);
    return n * 1000 + m * 5;
}

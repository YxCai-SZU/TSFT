#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer target_value(integer n) = n * 800 - (n / 15) * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == target_value(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t ans;
    uint32_t div;
    uint32_t temp_n;
    
    ans = 800 * (int32_t)n;
    div = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant div <= n / 15;
        loop invariant temp_n == n - div * 15;
        loop invariant ans == 800 * (int32_t)n;
        loop assigns temp_n, div;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        div += 1;
    }
    
    ans -= (int32_t)div * 200;
    
    //@ assert ans == target_value(n);
    return ans;
}

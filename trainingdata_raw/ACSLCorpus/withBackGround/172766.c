#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000000000;
    
    logic integer expected_result(integer n) = (n / 2) + (n % 2);
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t remainder;
    uint64_t ans;
    
    half_n = n / 2;
    remainder = n % 2;
    ans = half_n + remainder;
    
    //@ assert half_n == n / 2;
    //@ assert remainder == n % 2;
    //@ assert ans == half_n + remainder;
    //@ assert ans == expected_result(n);
    
    return ans;
}

#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bound:
        \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    uint32_t a;
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n * n;
    
    //@ assert n * n <= 10000;
    
    a = n * n;
    
    if (m >= a)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}

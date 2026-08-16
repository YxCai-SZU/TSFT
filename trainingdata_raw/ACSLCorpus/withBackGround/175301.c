#include <stdint.h>

/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    
    logic integer formula(integer n) = 180 * n - 360;
    
    lemma overflow_bound: \forall integer n; valid_n(n) ==> 180 * n <= 18000;
    lemma underflow_bound: \forall integer n; valid_n(n) ==> 180 * n - 360 >= 180;
*/

/*@
    requires valid_n(n);
    ensures \result == formula(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert valid_n(n);
    
    //@ assert 180 * n <= 18000;
    //@ assert 180 * n - 360 >= 180;
    
    ans = 180 * n - 360;
    
    //@ assert ans == formula(n);
    
    return ans;
}

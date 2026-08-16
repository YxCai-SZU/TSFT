#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer func_spec(integer n) = n * 800 - (n / 15) * 200;
    
    lemma n_div_bound: \forall integer n; valid_n(n) ==> n / 15 <= 6;
    lemma n_mul_bound: \forall integer n; valid_n(n) ==> n * 800 <= 80000;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert n / 15 <= 6;
    //@ assert n * 800 <= 80000;
    
    result = (int64_t)(n * 800 - (n / 15) * 200);
    return result;
}

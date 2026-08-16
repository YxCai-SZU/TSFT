#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer compute_result(integer n, integer a) =
        n * n - a;
*/

/*@
    requires valid_params(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at top of scope
    int32_t b;
    
    //@ assert n * n >= 0;
    //@ assert n * n <= 100 * 100;
    //@ assert n * n >= a;
    //@ assert n * n - a >= 0;
    
    b = n * n - a;
    return b;
}

/*@
    lemma result_non_negative:
        \forall integer n, a; valid_params(n, a) ==> compute_result(n, a) >= 0;
*/

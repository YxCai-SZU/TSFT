#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 100 &&
        1 <= b && b <= 2000 &&
        n * a <= 2000;

    logic integer compute_result(integer n, integer a, integer b) =
        n * a < b ? n * a : b;

    lemma result_properties:
        \forall integer n, a, b;
        valid_params(n, a, b) ==>
        (compute_result(n, a, b) == n * a || compute_result(n, a, b) == b) &&
        compute_result(n, a, b) <= b;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert n * a <= 2000;
    
    if (n * a < b) {
        ans = n * a;
    } else {
        ans = b;
    }
    
    //@ assert ans == n * a || ans == b;
    //@ assert ans <= b;
    
    return ans;
}

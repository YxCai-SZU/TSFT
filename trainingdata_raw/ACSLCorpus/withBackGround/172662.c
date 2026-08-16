#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer compute_bound(integer a, integer p) = p + a * 3;

    lemma ans_bounds:
        \forall integer a, p, ans;
        valid_range(a, p) && ans == (p + a * 3) / 2 ==>
        ans <= compute_bound(a, p) && ans >= (p + a * 3) / 2;
*/

/*@
    requires valid_range(A, P);
    ensures \result <= compute_bound(A, P);
    ensures \result >= (P + A * 3) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t ans;
    //@ assert valid_range(A, P);
    ans = (P + A * 3) / 2;
    //@ assert ans <= compute_bound(A, P);
    //@ assert ans >= (P + A * 3) / 2;
    return ans;
}

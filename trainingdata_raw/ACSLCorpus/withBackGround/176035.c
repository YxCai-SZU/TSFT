#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;

    logic integer calculate_bound(integer a, integer p) = a * 3 + p;

    lemma ans_bound_property:
        \forall integer a, p, ans;
        valid_range(a, p) && ans == (a * 3 + p) / 2 ==>
        ans <= calculate_bound(a, p) && ans >= 0;
*/

/*@
    requires valid_range(A, P);
    ensures \result <= calculate_bound(A, P);
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t ans;
    //@ assert valid_range(A, P);
    ans = (A * 3 + P) / 2;
    //@ assert ans <= calculate_bound(A, P);
    return ans;
}

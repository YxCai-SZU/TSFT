#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        (c - (a - b) > 0) ? (c - (a - b)) : 0;

    lemma ans_properties:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        (
            compute_ans(a, b, c) >= 0 &&
            compute_ans(a, b, c) <= c &&
            (compute_ans(a, b, c) == c - (a - b) || compute_ans(a, b, c) == 0)
        );
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert valid_params(a, b, c);
    
    if (c - (a - b) > 0) {
        ans = c - (a - b);
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans == c - (a - b) || ans == 0;
    
    return ans;
}

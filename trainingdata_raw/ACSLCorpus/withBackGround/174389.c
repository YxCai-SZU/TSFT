#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        (c - (a - b) < 0) ? 0 : (c - (a - b));

    lemma ans_nonnegative:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> compute_ans(a, b, c) >= 0;

    lemma ans_bounded_by_c:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> compute_ans(a, b, c) <= c;

    lemma ans_correct_form:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_ans(a, b, c) == c - (a - b) ||
        compute_ans(a, b, c) == 0;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans;
    
    //@ assert valid_input(a, b, c);
    
    ans = c - (a - b);
    
    if (ans < 0)
    {
        ans = 0;
    }
    
    return ans;
}

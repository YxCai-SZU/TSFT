#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        (c - (a - b)) < 0 ? 0 : (c - (a - b));

    lemma ans_properties:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        (
            compute_ans(a, b, c) >= 0 &&
            compute_ans(a, b, c) <= c &&
            (
                compute_ans(a, b, c) == c - (a - b) ||
                compute_ans(a, b, c) == 0
            )
        );
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= a;
    //@ assert 1 <= c && c <= 20;

    ans = c - (a - b);
    
    if (ans < 0)
    {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans == c - (a - b) || ans == 0;
    
    return ans;
}

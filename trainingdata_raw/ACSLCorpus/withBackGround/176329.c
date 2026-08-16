#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - (a - b)) < 0 ? 0 : (c - (a - b));

    lemma result_bounds:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        (
            compute_result(a, b, c) >= 0 &&
            compute_result(a, b, c) <= c &&
            (
                compute_result(a, b, c) == c - (a - b) ||
                compute_result(a, b, c) == 0
            )
        );
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int tmp;

    //@ assert 0 <= a - b <= 19;
    tmp = c - (a - b);
    //@ assert -19 <= tmp <= 20;
    
    if (tmp < 0)
    {
        result = 0;
    }
    else
    {
        result = tmp;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;
    
    return result;
}

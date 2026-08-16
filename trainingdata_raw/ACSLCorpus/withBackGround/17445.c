#include <limits.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_diff(integer a, integer b, integer c) =
        c - (a - b);

    logic integer compute_result(integer a, integer b, integer c) =
        (compute_diff(a, b, c) < 0) ? 0 : compute_diff(a, b, c);

    lemma diff_nonnegative_or_result_zero:
        \forall integer a, b, c;
            valid_inputs(a, b, c) ==>
            (compute_diff(a, b, c) >= 0) || (compute_result(a, b, c) == 0);

    lemma result_equals_diff_when_nonnegative:
        \forall integer a, b, c;
            valid_inputs(a, b, c) ==>
            (compute_diff(a, b, c) < 0) || (compute_result(a, b, c) == compute_diff(a, b, c));

    lemma diff_bounds:
        \forall integer a, b, c;
            valid_inputs(a, b, c) ==>
            0 <= a - b && a - b <= 20;

    lemma diff_le_c:
        \forall integer a, b, c;
            valid_inputs(a, b, c) ==>
            compute_diff(a, b, c) <= c;
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == compute_diff(a, b, c) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int diff;
    int result;

    //@ assert 0 <= a - b && a - b <= 20;
    diff = c - (a - b);
    
    //@ assert diff <= c;
    
    //@ assert diff >= 0 || (diff < 0 ? 0 : diff) == 0;
    
    //@ assert diff < 0 || (diff < 0 ? 0 : diff) == diff;
    
    if (diff < 0)
    {
        result = 0;
    }
    else
    {
        result = diff;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == diff || result == 0;
    
    return result;
}

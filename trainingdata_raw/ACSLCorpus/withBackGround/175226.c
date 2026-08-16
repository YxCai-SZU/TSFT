#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b <= a <= 20 && 1 <= c <= 20;

    logic integer min_val(integer a, integer b, integer c) =
        (a - b) < c ? (a - b) : c;

    logic integer compute_result(integer a, integer b, integer c) =
        c - min_val(a, b, c);

    lemma min_val_property:
        \forall integer a, b, c;
            valid_input(a, b, c) ==>
            min_val(a, b, c) == (a - b) || min_val(a, b, c) == c;

    lemma result_property:
        \forall integer a, b, c;
            valid_input(a, b, c) ==>
            compute_result(a, b, c) == c - (a - b) ||
            compute_result(a, b, c) == 0;
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
    int min_val;
    int result;

    //@ assert valid_input(a, b, c);

    if (a - b < c)
    {
        min_val = a - b;
    }
    else
    {
        min_val = c;
    }

    //@ assert min_val == a - b || min_val == c;

    result = c - min_val;

    //@ assert result == c - (a - b) || result == 0;

    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

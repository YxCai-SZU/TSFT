#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (0 > c - (a - b)) ? 0 : c - (a - b);

    lemma result_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_result(a, b, c) >= 0 &&
        compute_result(a, b, c) <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;

    //@ assert 0 <= c && c <= 20;
    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 0 <= a - b && a - b <= 19;
    //@ assert -19 <= c - (a - b) && c - (a - b) <= 20;

    if (0 > c - (a - b))
    {
        result = 0;
    }
    else
    {
        result = c - (a - b);
    }

    //@ assert result >= 0;
    //@ assert result <= c;

    return result;
}

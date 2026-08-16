#include <stdint.h>

/*@
    predicate valid_input(int32_t *a) =
        \valid(a) && \valid(a+1) &&
        a[0] >= -1000000000 && a[0] <= 1000000000 &&
        a[1] >= 1 && a[1] <= 1000000000;

    logic integer diff_or_zero(integer x, integer y) =
        (x - y > 0) ? (x - y) : 0;

    lemma diff_nonnegative:
        \forall integer x, y;
            (x - y > 0) ==> (x - y >= 0);
    lemma zero_nonnegative:
        0 >= 0;
*/

/*@
    requires valid_input(a);
    ensures \result >= 0;
    ensures \result == a[0] - a[1] || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t *a)
{
    int32_t result;
    int32_t diff;

    //@ assert a[0] >= -1000000000 && a[0] <= 1000000000;
    //@ assert a[1] >= 1 && a[1] <= 1000000000;

    diff = a[0] - a[1];

    //@ assert diff == a[0] - a[1];

    if (diff > 0)
    {
        //@ assert diff >= 0;
        result = diff;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == a[0] - a[1] || result == 0;

    return result;
}

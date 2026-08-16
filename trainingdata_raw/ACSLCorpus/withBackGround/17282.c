#include <stdint.h>

/*@
    predicate valid_inputs(integer x, integer a, integer b) =
        0 <= x <= 1000000000000000000 &&
        0 <= a <= 1000000000000000000 &&
        0 <= b <= 1000000000000000000;

    logic integer func_result(integer x, integer a, integer b) =
        x > a + b ? a + b :
        x < a ? a :
        a + (b - (x - a) < 0 ? 0 : b - (x - a));

    lemma result_non_negative:
        \forall integer x, a, b;
        valid_inputs(x, a, b) ==> func_result(x, a, b) >= 0;

    lemma result_bounded:
        \forall integer x, a, b;
        valid_inputs(x, a, b) ==> func_result(x, a, b) <= a + b;
*/

/*@
    requires valid_inputs(x, a, b);
    ensures \result >= 0;
    ensures \result <= a + b;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t a, int64_t b)
{
    int64_t result;
    int64_t y;
    int64_t ans;

    //@ assert valid_inputs(x, a, b);

    if (x > a + b)
    {
        //@ assert x > a + b;
        result = a + b;
    }
    else if (x < a)
    {
        //@ assert x < a;
        result = a;
    }
    else
    {
        //@ assert x >= a;
        y = x - a;
        if (b - y < 0)
        {
            ans = a + 0;
        }
        else
        {
            ans = a + (b - y);
        }
        result = ans;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b;
    return result;
}

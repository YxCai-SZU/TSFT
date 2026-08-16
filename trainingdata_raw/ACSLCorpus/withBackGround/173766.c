#include <stdint.h>

/*@
    predicate valid_inputs(integer x, integer a, integer b) =
        1 <= x && x <= 10000 &&
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000;

    logic integer compute_pay(integer x, integer a) =
        a > x ? a - x : 0;

    logic integer compute_result(integer x, integer a, integer b) =
        compute_pay(x, a) > b ? compute_pay(x, a) - b : 0;

    lemma result_nonnegative:
        \forall integer x, a, b;
        valid_inputs(x, a, b) ==> compute_result(x, a, b) >= 0;

    lemma result_bounded_by_a:
        \forall integer x, a, b;
        valid_inputs(x, a, b) ==> compute_result(x, a, b) <= a;
*/

/*@
    requires valid_inputs(x, a, b);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t a, int64_t b)
{
    int64_t pay;
    int64_t result;

    //@ assert valid_inputs(x, a, b);

    if (a > x)
    {
        pay = a - x;
    }
    else
    {
        pay = 0;
    }

    //@ assert pay == compute_pay(x, a);

    if (pay > b)
    {
        result = pay - b;
    }
    else
    {
        result = 0;
    }

    //@ assert result == compute_result(x, a, b);
    //@ assert result >= 0;
    //@ assert result <= a;

    return result;
}

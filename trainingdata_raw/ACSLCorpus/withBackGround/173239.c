#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b;

    lemma result_property:
        \forall integer a, b;
        valid_range(a, b) ==>
        (compute_result(a, b) < 0 ==> 0 >= 0) &&
        (compute_result(a, b) >= 0 ==> compute_result(a, b) >= 0);
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == compute_result(a, b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    result = a - 2 * b;
    //@ assert result == compute_result(a, b);
    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
    }
    else
    {
        //@ assert result >= 0;
    }
    //@ assert result >= 0;
    //@ assert result == compute_result(a, b) || result == 0;
    return result;
}

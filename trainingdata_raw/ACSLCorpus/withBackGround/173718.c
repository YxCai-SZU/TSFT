#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b) =
        2 <= a && a <= 20 &&
        1 <= b && b <= 20;

    logic integer compute_result(integer a, integer b) =
        (b - 1) / (a - 1) + 1;

    lemma result_properties:
        \forall integer a, b;
        valid_input(a, b) ==>
        compute_result(a, b) >= 1 &&
        compute_result(a, b) <= 20;
*/

/*@
    requires valid_input(a, b);
    ensures \result >= 1;
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t result;
    //@ assert valid_input(a, b);
    result = (b - 1) / (a - 1) + 1;
    //@ assert result >= 1;
    //@ assert result == compute_result(a, b);
    return result;
}

#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma bounds_lemma:
        \forall integer a, b;
            valid_range(a, b) ==>
                1 <= a - 1 && a - 1 <= 99 &&
                1 <= b - 1 && b - 1 <= 99;

    lemma product_bounds_lemma:
        \forall integer a, b;
            valid_range(a, b) ==>
                compute_result(a, b) <= 99 * 99;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 1 <= a - 1;
    //@ assert 1 <= b - 1;
    //@ assert a - 1 <= 99;
    //@ assert b - 1 <= 99;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;

    result = (a - 1) * (b - 1);
    return result;
}

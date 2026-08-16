#include <stddef.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma no_overflow_mul:
        \forall integer a, b;
            is_valid_range(a, b) ==> a * b <= 100 * 100;

    lemma no_overflow_add:
        \forall integer a, b;
            is_valid_range(a, b) ==> a + b <= 100 + 100;

    lemma no_underflow_sub:
        \forall integer a, b;
            is_valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t mul_result;
    size_t add_result;
    size_t sub_result;
    size_t final_result;

    //@ assert a * b <= 100 * 100;
    mul_result = a * b;

    //@ assert a + b <= 100 + 100;
    add_result = a + b;

    //@ assert mul_result >= add_result - 1;
    sub_result = add_result - 1;
    final_result = mul_result - sub_result;

    return final_result;
}

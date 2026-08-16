#include <stddef.h>
/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a < b * 2 ? 0 : a - (b * 2);

    lemma result_property:
        \forall integer a, b;
        valid_input(a, b) ==> compute_result(a, b) >= 0;
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    ensures \result >= 0;
*/
size_t func(size_t a, size_t b) {
    size_t result;
    size_t min_val;
    size_t b_times_2;

    //@ assert valid_input(a, b);
    b_times_2 = b * 2;
    //@ assert b_times_2 == b * 2;

    if (a < b_times_2) {
        min_val = a;
    } else {
        min_val = b_times_2;
    }

    if (min_val == a) {
        result = 0;
    } else {
        //@ assert a >= b_times_2;
        //@ assert a >= 1 && a <= 100;
        //@ assert b >= 1 && b <= 100;
        result = a - b_times_2;
    }

    //@ assert result == compute_result(a, b);
    //@ assert result >= 0;
    return result;
}

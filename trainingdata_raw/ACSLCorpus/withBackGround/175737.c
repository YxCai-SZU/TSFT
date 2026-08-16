#include <stdbool.h>

/*@
    predicate min_val_in_range(integer a, integer b, integer min_val) =
        (a < b ==> min_val == a) && (a >= b ==> min_val == b) &&
        3 <= min_val && min_val <= 20;

    predicate max_val_in_range(integer a, integer b, integer max_val) =
        (a > b ==> max_val == a) && (a <= b ==> max_val == b) &&
        3 <= max_val && max_val <= 20;

    logic integer compute_result(integer a, integer b, integer min_val, integer max_val) =
        (max_val - min_val < 2) ? (max_val + min_val) : (2 * max_val - 1);

    lemma result_properties:
        \forall integer a, b, min_val, max_val, result;
        min_val_in_range(a, b, min_val) && max_val_in_range(a, b, max_val) &&
        result == compute_result(a, b, min_val, max_val) ==>
        (result == a + b || result == 2 * a - 1 || result == 2 * b - 1) &&
        result >= 2;
*/

/*@
    requires 3 <= a <= 20;
    requires 3 <= b <= 20;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 2;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int result;

    // Calculate min_val
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    //@ assert min_val_in_range(a, b, min_val);

    // Calculate max_val
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    //@ assert max_val_in_range(a, b, max_val);

    // Calculate result
    if (max_val - min_val < 2) {
        result = max_val + min_val;
    } else {
        result = 2 * max_val - 1;
    }

    //@ assert result == compute_result(a, b, min_val, max_val);
    return result;
}

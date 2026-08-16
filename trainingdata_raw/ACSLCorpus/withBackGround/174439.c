#include <stdbool.h>

/*@
    predicate valid_vec(int *v) =
        \valid(v + (0..3)) &&
        v[0] >= -100 && v[0] <= 100 &&
        v[1] >= -100 && v[1] <= 100 &&
        v[2] >= -100 && v[2] <= 100 &&
        v[3] >= -100 && v[3] <= 100;

    logic integer max_val(integer a, integer b) = a > b ? a : b;

    lemma max_val_property:
        \forall integer a, b;
            max_val(a, b) == a || max_val(a, b) == b;

    lemma result_property:
        \forall integer a, b, c, d;
            max_val(a, b) + max_val(c, d) == a + c ||
            max_val(a, b) + max_val(c, d) == a + d ||
            max_val(a, b) + max_val(c, d) == b + c ||
            max_val(a, b) + max_val(c, d) == b + d;
*/

/*@
    requires valid_vec(v);
    ensures \result == v[0] + v[2] ||
            \result == v[0] + v[3] ||
            \result == v[1] + v[2] ||
            \result == v[1] + v[3];
    assigns \nothing;
*/
int func(int *v)
{
    int max_val;
    int max_val2;
    int result;

    //@ assert v[0] >= -100 && v[0] <= 100;
    //@ assert v[1] >= -100 && v[1] <= 100;
    //@ assert v[2] >= -100 && v[2] <= 100;
    //@ assert v[3] >= -100 && v[3] <= 100;

    if (v[0] > v[1]) {
        max_val = v[0];
    } else {
        max_val = v[1];
    }

    //@ assert max_val == v[0] || max_val == v[1];

    if (v[2] > v[3]) {
        max_val2 = v[2];
    } else {
        max_val2 = v[3];
    }

    //@ assert max_val2 == v[2] || max_val2 == v[3];

    result = max_val + max_val2;

    //@ assert result == v[0] + v[2] || result == v[0] + v[3] || result == v[1] + v[2] || result == v[1] + v[3];

    return result;
}

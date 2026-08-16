#include <stdbool.h>

/*@
    predicate is_within_range(integer a, integer b) =
        1 <= a <= 16 && 1 <= b <= 16 && a + b <= 16;

    logic integer max_val(integer a, integer b) =
        a > b ? a : b;

    lemma max_val_property:
        \forall integer a, b;
        is_within_range(a, b) ==> 
        max_val(a, b) == a || max_val(a, b) == b;
*/

/*@
    requires is_within_range(a, b);
    ensures \result == (a <= 8 || b <= 8);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int max_val;
    bool result;

    // Variable declarations at scope top
    max_val = 0;
    result = false;

    // Manual max implementation
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    //@ assert max_val == a || max_val == b;

    result = (a <= 8) || (b <= 8);
    return result;
}

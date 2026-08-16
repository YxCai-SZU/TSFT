#include <stdbool.h>

/*@
    predicate min_is_a_or_x(integer a, integer x, integer min_val) =
        min_val == a || min_val == x;
    predicate max_is_sum(integer a, integer b, integer max_val) =
        max_val == a + b;
    predicate condition_holds(integer a, integer b, integer x) =
        x <= a + b && a <= x;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (x <= a + b && a <= x);
*/
bool func(unsigned long a, unsigned long b, unsigned long x)
{
    unsigned long min_val;
    unsigned long max_val;
    bool result;

    // Calculate min_val
    if (a < x) {
        min_val = a;
    } else {
        min_val = x;
    }

    // Calculate max_val
    max_val = a + b;

    // Verification assertions
    //@ assert min_is_a_or_x(a, x, min_val);
    //@ assert max_is_sum(a, b, max_val);

    if (x <= max_val && min_val == a) {
        //@ assert condition_holds(a, b, x);
        result = true;
    } else {
        //@ assert !condition_holds(a, b, x);
        result = false;
    }

    return result;
}

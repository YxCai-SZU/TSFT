#include <stdbool.h>

/*@
    predicate is_in_range(integer a, integer b, integer x) =
        a >= 0 && a <= 100 &&
        b >= 0 && b <= 100 &&
        x >= 0 && x <= 100;

    predicate result_condition(integer a, integer b, integer x, bool result) =
        result == (x >= a && x <= a + b);
*/

/*@
    requires is_in_range(a, b, x);
    ensures result_condition(a, b, x, \result);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long max_val;
    unsigned long long x_minus_a;
    unsigned long long min_val;
    bool result;

    //@ assert is_in_range(a, b, x);

    if (x >= a) {
        max_val = x;
    } else {
        max_val = a;
    }

    if (x >= a) {
        x_minus_a = x - a;
    } else {
        x_minus_a = 0;
    }

    if (b >= x_minus_a) {
        min_val = x_minus_a;
    } else {
        min_val = b;
    }

    //@ assert x >= a && x <= a + b ==> (x >= a && x <= a + b);

    result = (x >= a && x <= a + b);
    //@ assert result_condition(a, b, x, result);
    return result;
}

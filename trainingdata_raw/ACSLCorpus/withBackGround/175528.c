#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 200;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (a <= x && x - a < b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long x)
{
    // Variable declarations at top of scope
    bool result;

    if (a > x) {
        result = false;
    } else if (x - a < b) {
        result = true;
    } else {
        //@ assert x - a >= b || a > x;
        result = false;
    }

    return result;
}

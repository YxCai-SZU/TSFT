#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;
*/

/*@
    requires in_range(d) && in_range(t) && in_range(s);
    ensures \result == (d <= s * t);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;
    int product;

    //@ assert 1 <= d <= 10000;
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;

    // Check for potential overflow
    //@ assert s * t <= 10000 * 10000;

    product = s * t;
    result = (d <= product);

    return result;
}

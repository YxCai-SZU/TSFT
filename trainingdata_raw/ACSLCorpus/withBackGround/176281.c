#include <stdbool.h>

/*@
    predicate is_square_eq_self(integer x) = x * x == x;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a * a == a || b * b == b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 * 1 <= a * a <= 100 * 100;
    //@ assert 1 * 1 <= b * b <= 100 * 100;

    result = (a * a == a) || (b * b == b);
    return result;
}

#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    predicate condition_holds(integer a, integer b) =
        a > b || a % 3 == 0 || a % 5 == 0 || b % 3 == 0 || b % 5 == 0;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    ensures \result <==> condition_holds(a, b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a % 3 == a % 3;
    result = (a > b) || (a % 3 == 0) || (a % 5 == 0) || (b % 3 == 0) || (b % 5 == 0);
    return result;
}

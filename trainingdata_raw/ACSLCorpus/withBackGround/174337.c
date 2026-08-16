#include <stdbool.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && n <= 16 &&
        1 <= m && m <= 16 &&
        n + m <= 16;

    predicate both_small(integer n, integer m) =
        n <= 8 && m <= 8;
*/

/*@
    requires valid_input(n, m);
    ensures \result == true <==> both_small(n, m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;

    if (n > 8 || m > 8) {
        //@ assert n > 8 || m > 8;
        result = false;
    } else {
        //@ assert n <= 8 && m <= 8;
        result = true;
    }

    return result;
}

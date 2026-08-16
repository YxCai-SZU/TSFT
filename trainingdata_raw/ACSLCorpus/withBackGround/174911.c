#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (m <= n);
    assigns \nothing;
*/
bool func(int n, int m)
{
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    return m <= n;
}

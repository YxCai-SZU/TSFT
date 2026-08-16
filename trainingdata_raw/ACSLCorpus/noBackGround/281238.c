#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (x) <= 100);
    ensures \result == (b <= x && x <= a + b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 <= a + b <= 200;

    result = (b <= x) && (x <= a + b);
    return result;
}

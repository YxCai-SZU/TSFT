#include <stdbool.h>

/*@
    requires 1 <= n && n <= 10000;
    requires 1 <= m && m <= 10000;
    requires 1 <= a && a <= 10000;
    ensures \result == (n >= m * a);
*/
bool func(int n, int m, int a)
{
    // Variable declarations at top of scope
    bool result;

    // Verification of multiplication bounds
    //@ assert m <= 10000;
    //@ assert a <= 10000;
    //@ assert (1 <= (m) && (m) <= 10000 &&         1 <= (a) && (a) <= 10000 &&         (m) * (a) <= 10000 * 10000);

    result = (n >= m * a);
    return result;
}

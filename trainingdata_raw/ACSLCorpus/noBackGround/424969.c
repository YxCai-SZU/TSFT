#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;

    result = (n == m);
    return result;
}


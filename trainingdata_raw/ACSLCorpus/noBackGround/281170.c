#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    bool res;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;

    res = (n == m);
    return res;
}

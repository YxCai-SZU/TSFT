#include <limits.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    int res;
    //@ assert (2 <= (n) <= 100 && 2 <= (m) <= 100);
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert 1 <= (n - 1) * (m - 1) <= 9801;
    res = (n - 1) * (m - 1);
    //@ assert res == (((n) - 1) * ((m) - 1));
    return res;
}

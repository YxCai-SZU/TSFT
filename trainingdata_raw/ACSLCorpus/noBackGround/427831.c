#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= m && m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert n == m ==> n == m;
    result = (n == m);
    return result;
}

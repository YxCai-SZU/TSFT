#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    bool result;
    //@ assert n == m ==> n == m;
    result = (n == m);
    return result;
}

#include <stdbool.h>
/*@
    requires 2 <= n && n <= 100;
    requires 2 <= m && m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert n >= 2 && n <= 100;
    //@ assert m >= 2 && m <= 100;
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    return (n - 1) * (m - 1);
}

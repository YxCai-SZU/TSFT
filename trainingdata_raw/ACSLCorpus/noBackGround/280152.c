#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n));
    return n == m;
}

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func2(int n, int m)
{
    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n));
    //@ assert 0 <= n <= 100;
    //@ assert 0 <= m <= n;
    //@ assert n - m >= 0;
    return n == m;
}

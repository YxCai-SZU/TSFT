#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == (n + m <= a + b);
    assigns \nothing;
*/
bool func(int n, int m, int a, int b)
{
    int x;
    int y;
    bool result;

    if (n < m)
    {
        x = n;
    }
    else
    {
        x = m;
    }

    if (a < b)
    {
        y = a;
    }
    else
    {
        y = b;
    }

    //@ assert ((x) == (n) || (x) == (m));
    //@ assert ((y) == (a) || (y) == (b));
    //@ assert x == n || x == m;
    //@ assert y == a || y == b;

    result = (n + m <= a + b);
    return result;
}

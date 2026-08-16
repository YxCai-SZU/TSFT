#include <stdbool.h>

/*@
    requires ((1) <= (n) && (n) <= (100));
    requires ((1) <= (m) && (m) <= (100));
    ensures \result == (n - 2 * m >= 0 && n - 2 * m <= m);
*/
bool func(int n, int m)
{
    int a;
    bool result;

    a = n - 2 * m;
    //@ assert a == n - 2 * m;

    if (a < 0 || a > m)
    {
        //@ assert a < 0 || a > m;
        result = false;
    }
    else
    {
        //@ assert a >= 0 && a <= m;
        result = true;
    }

    return result;
}

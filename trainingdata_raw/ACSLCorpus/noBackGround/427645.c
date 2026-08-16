#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= m <= 1000;
    ensures \result == (n >= m * 2 && n % 2 == 0);
*/
bool func(int n, int m)
{
    bool result;
    result = false;

    //@ assert n >= 1 && n <= 10000;
    //@ assert m >= 0 && m <= 1000;

    if (n >= m * 2 && n % 2 == 0)
    {
        result = true;
    }

    //@ assert result == (n >= m * 2 && n % 2 == 0);
    return result;
}

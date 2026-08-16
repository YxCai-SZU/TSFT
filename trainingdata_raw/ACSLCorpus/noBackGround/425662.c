#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == (x >= 2000 || (100 * (x / 100) <= x && x % 100 <= 5 * (x / 100)));
    assigns \nothing;
 */
bool func(unsigned long long x)
{
    unsigned long long n;
    unsigned long long b;
    bool result;

    n = x / 100;
    b = x % 100;

    //@ assert n == x / 100;
    //@ assert b == x % 100;

    if (x >= 2000)
    {
        result = true;
    }
    else
    {
        result = (100 * n <= x) && (b <= 5 * n);
    }

    //@ assert result == (x >= 2000 || (100 * n <= x && b <= 5 * n));
    return result;
}

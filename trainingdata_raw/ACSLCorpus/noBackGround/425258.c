#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (x <= a && a - x <= b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long remaining;

    if (x > a)
    {
        //@ assert !(x <= a && a - x <= b);
        return false;
    }

    remaining = a - x;

    if (remaining > b)
    {
        //@ assert !(x <= a && a - x <= b);
        return false;
    }

    //@ assert x <= a && a - x <= b;
    return true;
}

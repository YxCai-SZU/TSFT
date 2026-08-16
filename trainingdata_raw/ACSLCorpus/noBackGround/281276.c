#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 200;
    ensures \result == (x <= a + b && a <= x);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long c;
    bool result;

    c = a + b;

    if (x <= c && a <= x)
    {
        //@ assert ((x) <= (a) + (b) && (a) <= (x));
        result = true;
    }
    else
    {
        //@ assert !((x) <= (a) + (b) && (a) <= (x));
        result = false;
    }

    return result;
}

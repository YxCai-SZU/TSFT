#include <stdbool.h>

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= x && x <= 100;
    ensures \result == (x - a >= 0 && x - a <= b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    long min;
    long max;
    long p;

    min = 0;
    max = b + 1;
    p = x - a;

    //@ assert p == x - a;

    return p >= min && p <= b && p == x - a;
}

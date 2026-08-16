#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations
    int64_t res;

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    if (a * b > c * d)
    {
        res = a * b;
    }
    else
    {
        res = c * d;
    }

    return res;
}

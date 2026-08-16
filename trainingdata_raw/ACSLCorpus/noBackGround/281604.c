#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 10000 &&
        0 <= (b) && (b) <= 10000 &&
        0 <= (c) && (c) <= 10000 &&
        0 <= (d) && (d) <= 10000 &&
        (a) <= (b) &&
        (b) - (a) >= (c) &&
        (c) <= (d));
    ensures \result <= d;
    ensures \result >= c;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t s;
    uint32_t t;
    uint32_t ans;

    //@ assert (0 <= (a) && (a) <= 10000 &&         0 <= (b) && (b) <= 10000 &&         0 <= (c) && (c) <= 10000 &&         0 <= (d) && (d) <= 10000 &&         (a) <= (b) &&         (b) - (a) >= (c) &&         (c) <= (d));
    s = b - a;
    //@ assert s == ((b) - (a));
    t = d - c;
    //@ assert t == ((d) - (c));

    if (s > t)
    {
        ans = t + c;
        //@ assert ans == t + c;
        //@ assert ans <= d;
        //@ assert ans >= c;
    }
    else
    {
        ans = s + c;
        //@ assert ans == s + c;
        //@ assert ans <= d;
        //@ assert ans >= c;
    }

    return ans;
}

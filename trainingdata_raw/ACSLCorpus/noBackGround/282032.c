#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x = 0;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((a) + (b) + (c) + (d)) >= 0;

    if (a + b + c + d == 0)
    {
        x = 0;
    }
    else if (a >= b + c + d)
    {
        x = b + c;
    }
    else if (a + b >= c + d)
    {
        x = d;
    }
    else if (a + b + c >= d)
    {
        x = b + c;
    }

    //@ assert x >= 0;
    //@ assert x <= a + b + c + d;

    return x;
}

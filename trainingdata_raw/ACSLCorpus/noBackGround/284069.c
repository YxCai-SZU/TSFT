#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
    ensures \result == ((c) > (b) ?
            ((b) + (d) >= (c) ? 0 : (c) - (b) - (d))
        : (b) > (c) ?
            ((c) + (d) >= (b) ? 0 : (b) - (c) - (d))
        : 0);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t result;

    if (c > b)
    {
        if (b + d >= c)
        {
            //@ assert b + d >= c;
            result = 0;
        }
        else
        {
            //@ assert b + d < c;
            result = c - b - d;
        }
    }
    else if (b > c)
    {
        if (c + d >= b)
        {
            //@ assert c + d >= b;
            result = 0;
        }
        else
        {
            //@ assert c + d < b;
            result = b - c - d;
        }
    }
    else
    {
        //@ assert c == b;
        result = 0;
    }

    return result;
}

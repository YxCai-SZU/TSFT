#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= -1 && \result <= 20;
    ensures \result >= 0 ==> \result < c;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t res;
    uint32_t diff;

    if (a < b)
    {
        if (b < c)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    else
    {
        if (a <= c)
        {
            //@ assert a <= c;
            diff = c - a;

            //@ assert ((c) - (a)) == diff;
            //@ assert 0 <= diff && diff <= 19;
            
            if (diff > b)
            {
                res = (int32_t)b;
            }
            else
            {
                res = -1;
            }
        }
        else
        {
            res = -1;
        }
    }

    //@ assert res >= -1 && res <= 20;
    return res;
}

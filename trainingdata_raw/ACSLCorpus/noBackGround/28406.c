#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == 0 || \result == 1 || \result == 2;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    if (c <= b)
    {
        if (a <= c)
        {
            //@ assert 1 <= a <= 10000;
            return 1;
        }
        else
        {
            //@ assert 0 <= a <= 10000;
            return 0;
        }
    }
    else
    {
        if (a <= b)
        {
            //@ assert 1 <= a <= 10000;
            return 2;
        }
        else
        {
            //@ assert 0 <= a <= 10000;
            return 0;
        }
    }
}

#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + d || 
            \result == a + b + c || \result == a + b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t train;
    uint32_t result;

    train = a + b + c + d;

    //@ assert train == ((a) + (b) + (c) + (d));

    if (train <= d)
    {
        //@ assert train <= d;
        result = a + c;
        //@ assert result == ((a) + (c));
        return result;
    }
    else if (train <= a + c)
    {
        //@ assert train <= ((a) + (c));
        result = b + d;
        //@ assert result == (((d)) + (d));
        return result;
    }
    else
    {
        //@ assert train > ((a) + (c));
        result = a + b + c;
        //@ assert result == a + b + c;
        return result;
    }
}

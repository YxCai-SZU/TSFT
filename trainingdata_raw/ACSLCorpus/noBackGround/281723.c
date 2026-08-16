#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (int)(a * b + 1) || \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    int32_t result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert a * b <= (100 * 100);

    product = a * b;

    //@ assert product <= (100 * 100);

    if (product < 100 * 100)
    {
        result = (int32_t)(product + 1);
        //@ assert result == (int)(a * b + 1);
        return result;
    }
    else
    {
        result = -1;
        //@ assert result == -1;
        return result;
    }
}

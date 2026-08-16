#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (int)(a * b) || \result == 0;
    ensures \result >= 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t local_a = a;
    uint32_t local_b = b;
    int32_t result;

    if (local_a >= 13 || local_b >= 13)
    {
        result = 0;
    }
    else
    {
        //@ assert local_a >= 1 && local_a <= 12;
        //@ assert local_b >= 1 && local_b <= 12;
        //@ assert local_a * local_b <= 144;
        result = (int32_t)(local_a * local_b);
    }

    return result;
}

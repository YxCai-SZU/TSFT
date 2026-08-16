#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= a + b + c;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert a + b <= 200;
    //@ assert a + b + c <= 300;

    uint32_t ret;

    ret = a + b + c;

    if (c % 2 == 0)
    {
        ret -= 1;
    }
    else
    {
        ret -= 2;
    }

    return ret;
}

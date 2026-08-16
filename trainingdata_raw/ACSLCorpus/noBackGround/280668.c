#include <stdint.h>

/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;

    //@ assert ((a) >= 0);
    //@ assert ((b) >= 0);

    if (a > b * 2)
    {
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }

    //@ assert ((result) == (a) - (b) * 2 || (result) == 0);
    return result;
}

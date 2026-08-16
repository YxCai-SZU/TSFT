#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x / 100) * 100 < x;
    ensures \result == 0 ==> (x / 100) * 100 >= x;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp;

    //@ assert (1 <= (x) <= 100000);
    //@ assert ((x) / 100) <= 1000;
    //@ assert (((x) / 100) * 100) <= 100000;

    temp = (x / 100) * 100;

    if (temp < x)
    {
        //@ assert temp < x;
        result = 1;
    }
    else
    {
        //@ assert temp >= x;
        result = 0;
    }

    return result;
}

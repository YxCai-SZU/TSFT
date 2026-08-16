#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (((a) + (b)) / 2) || \result == (((a) + (b) + 1) / 2);
    ensures 1 <= \result <= 100;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t mean;
    int32_t result;

    sum = a + b;
    mean = sum / 2;

    if (sum % 2 != 0)
    {
        //@ assert mean < 100;
        result = (int32_t)(mean + 1);
    }
    else
    {
        //@ assert mean >= 1;
        result = (int32_t)mean;
    }

    return result;
}

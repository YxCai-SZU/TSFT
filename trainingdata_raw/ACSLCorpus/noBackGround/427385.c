#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == 0 ==> n % 1000 == 0;
    ensures \result > 0 ==> n % 1000 + \result == 1000;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t remainder;
    int32_t result;

    n_unsigned = (n < 0) ? (uint32_t)(-n) : (uint32_t)n;
    remainder = n_unsigned % 1000u;

    if (remainder == 0u)
    {
        result = 0;
        //@ assert (0 <= (remainder) < 1000);
        return result;
    }
    else
    {
        //@ assert (0 <= (remainder) < 1000);
        //@ assert 1000u - remainder < 1000u;
        result = (int32_t)(1000u - remainder);
        return result;
    }
}

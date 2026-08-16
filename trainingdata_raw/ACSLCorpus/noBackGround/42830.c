#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 10000);
    ensures \result == ((N) % 1000 == 0 ? 0 : 1000 - ((N) % 1000));
    ensures \result >= 0 && \result < 1000;
*/
int32_t func(int32_t N)
{
    uint32_t N_unsigned;
    uint32_t remainder;
    int32_t result;

    // Convert to unsigned integer
    if (N < 0)
    {
        N_unsigned = (uint32_t)(-N);
    }
    else
    {
        N_unsigned = (uint32_t)N;
    }

    // Calculate the remainder
    remainder = N_unsigned % 1000U;

    // Compute result
    if (remainder == 0U)
    {
        result = 0;
    }
    else
    {
        result = 1000 - (int32_t)remainder;
    }

    //@ assert result == 1000 - (N % 1000) || result == 0;
    //@ assert result >= 0;
    //@ assert result < 1000;

    return result;
}

#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == 0 || \result == 1000 - (n % 1000) || \result == 1000;
    ensures 0 <= \result && \result <= 1000;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t remainder;
    uint32_t result;
    int32_t final_result;

    //@ assert (1 <= (n) && (n) <= 10000);

    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }

    remainder = n_unsigned % 1000U;
    result = (1000U - remainder) % 1000U;

    //@ assert result == ((n) < 0 ?             -((1000 - ((-(n)) % 1000)) % 1000)         :             (1000 - ((n) % 1000)) % 1000);

    if (n < 0) {
        final_result = -(int32_t)result;
    } else {
        final_result = (int32_t)result;
    }

    //@ assert final_result == ((n) < 0 ?             -((1000 - ((-(n)) % 1000)) % 1000)         :             (1000 - ((n) % 1000)) % 1000);
    return final_result;
}

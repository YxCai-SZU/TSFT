#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100);
    ensures \result == ((N) * 800 - ((N) / 15 * 200));
    assigns \nothing;
*/
int32_t func(int32_t N)
{
    uint32_t N_unsigned;
    uint32_t quotient;
    int32_t quotient_signed;
    int32_t result;

    N_unsigned = (uint32_t)N;
    quotient = N_unsigned / 15;
    quotient_signed = (int32_t)quotient;
    result = N * 800 - quotient_signed * 200;

    //@ assert result == N * 800 - (N / 15 * 200);
    return result;
}

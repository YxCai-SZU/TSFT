#include <stdint.h>

/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20) && (1 <= (T) <= 20);
    ensures \result == (((T) / (A)) * (B));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t T)
{
    // Variable declarations at top of scope
    uint32_t quotient;
    uint32_t result;

    //@ assert 1 <= A <= 20;
    //@ assert 1 <= B <= 20;
    //@ assert 1 <= T <= 20;

    quotient = T / A;
    //@ assert quotient <= 20;

    //@ assert quotient * B <= 400;

    result = quotient * B;
    //@ assert result == (((T) / (A)) * (B));

    return result;
}

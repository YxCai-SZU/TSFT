#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        1 <= (M) && (M) <= 100);
    ensures \result == (((N) * 2 + (M)) / 4);
*/
int32_t func(uint32_t N, uint32_t M)
{
    // Variable declarations
    uint32_t result;
    uint32_t quotient = 0;
    uint32_t remainder;
    uint32_t divisor = 4;

    // Precondition check
    //@ assert (1 <= (N) && (N) <= 100 &&         1 <= (M) && (M) <= 100);

    result = N * 2 + M;
    remainder = result;

    /*@
        loop invariant quotient * divisor + remainder == result;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }

    // Postcondition verification
    //@ assert quotient == (((N) * 2 + (M)) / 4);
    return (int32_t)quotient;
}

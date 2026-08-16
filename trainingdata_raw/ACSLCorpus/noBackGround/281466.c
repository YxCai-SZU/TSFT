#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / (3));
    assigns \nothing;
*/
uint32_t func(uint32_t N)
{
    uint32_t quotient = 0;
    uint32_t remainder = N;
    uint32_t divisor = 3;

    /*@
        loop invariant 0 <= quotient <= N / divisor;
        loop invariant 0 <= remainder <= N;
        loop invariant remainder == N - quotient * divisor;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == N - quotient * divisor;
    }

    //@ assert remainder < divisor;
    return quotient;
}

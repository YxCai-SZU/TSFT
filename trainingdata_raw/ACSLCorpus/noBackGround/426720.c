#include <stdbool.h>

/*@
    requires (1 <= (N) <= 10000 && 0 <= (A) <= 1000);
    ensures \result == (N % 500 <= A);
*/
bool func(unsigned int N, unsigned int A)
{
    unsigned int quotient = 0;
    unsigned int remainder = N;
    const unsigned int divisor = 500;
    unsigned int remainder_N;

    /*@
        loop invariant 1 <= N <= 10000;
        loop invariant 0 <= A <= 1000;
        loop invariant 0 <= quotient <= ((N) / (divisor));
        loop invariant remainder == N - quotient * divisor;
        loop invariant 0 <= remainder <= N;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    remainder_N = remainder;

    //@ assert 0 <= quotient * divisor <= 10000 * 500;

    return remainder_N <= A;
}

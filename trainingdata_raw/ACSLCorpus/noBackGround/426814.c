#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
    ensures \result == ((A) * 3 + (P)) / 2;
*/
int64_t func(int64_t A, int64_t P)
{
    int64_t result;
    int64_t quotient;
    int64_t remainder;
    
    result = A * 3 + P;
    quotient = 0;
    remainder = result;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((A) * 3 + (P)) / 2;
        loop invariant remainder == result - 2 * quotient;
        loop invariant (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
        loop invariant result == ((A) * 3 + (P));
        loop assigns quotient, remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder == result - 2 * quotient;
        quotient = quotient + 1;
        remainder = remainder - 2;
        //@ assert remainder == result - 2 * quotient;
    }
    
    //@ assert remainder == result - 2 * quotient;
    //@ assert 0 <= remainder && remainder < 2;
    //@ assert quotient == ((A) * 3 + (P)) / 2;
    
    return quotient;
}

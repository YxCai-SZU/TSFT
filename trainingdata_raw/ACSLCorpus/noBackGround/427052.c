#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == a * 800 - ((a / 15) * 200 + (a % 15) * 4);
*/
int64_t func(int64_t a)
{
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    int64_t result;

    quotient = 0;
    remainder = a;
    divisor = 15;

    /*@
        loop invariant ((divisor) == 15 &&
        0 <= (quotient) <= (a) / 15 &&
        (remainder) == (a) - (quotient) * 15 &&
        (remainder) >= 0);
        loop invariant 1 <= a <= 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder == a - quotient * 15;
        quotient = quotient + 1;
        remainder = remainder - divisor;
        //@ assert remainder == a - quotient * 15;
    }

    //@ assert quotient == a / 15;
    //@ assert remainder == a % 15;
    result = a * 800 - (quotient * 200 + remainder * 4);
    //@ assert result == a * 800 - ((a / 15) * 200 + (a % 15) * 4);
    return result;
}

int main()
{
    return 0;
}

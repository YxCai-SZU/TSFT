#include <stdint.h>

/*@
    requires 1 <= x <= 1000000000000000;
    ensures \result >= 0;
    ensures \result <= (x / 11) * 2 + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t quotient;
    uint64_t remainder;
    uint64_t result;

    quotient = x / 11;
    remainder = x % 11;

    //@ assert (1 <= (x) <= 1000000000000000);
    //@ assert quotient == ((x) / 11);
    //@ assert remainder == ((x) % 11);

    if (remainder > 6)
    {
        //@ assert remainder > 6;
        //@ assert 0 <= 2 * quotient + 2 <= 2 * (x / 11) + 2;
        result = 2 * quotient + 2;
    }
    else if (remainder > 0)
    {
        //@ assert remainder > 0 && remainder <= 6;
        //@ assert 0 <= 2 * quotient + 1 <= 2 * (x / 11) + 1;
        result = 2 * quotient + 1;
    }
    else
    {
        //@ assert remainder == 0;
        //@ assert 0 <= 2 * quotient <= 2 * (x / 11);
        result = 2 * quotient;
    }

    //@ assert result >= 0;
    //@ assert result <= (x / 11) * 2 + 2;
    return result;
}

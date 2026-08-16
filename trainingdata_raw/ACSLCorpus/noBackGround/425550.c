#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == (((n) % 1000 == 0) ? 0 : 1000 - ((n) % 1000));
    ensures (n % 1000 == 0) ==> \result == 0;
    ensures (n % 1000 != 0) ==> \result == 1000 - (n % 1000);
*/
uint32_t func(uint32_t n)
{
    uint32_t three_digit;
    uint32_t remainder;
    uint32_t result;

    three_digit = n / 1000;
    remainder = n % 1000;

    if (remainder == 0)
    {
        //@ assert n % 1000 == 0;
        result = 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        result = 1000 - remainder;
    }

    return result;
}

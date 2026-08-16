#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000000000);
    ensures \result >= ((((x)) / 11) * 2);
    ensures \result <= ((((x)) / 11) * 2 + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t quotient;
    uint64_t remainder;
    uint64_t res;

    //@ assert (1 <= (x) && (x) <= 1000000000000000);
    quotient = x / 11;
    remainder = x % 11;
    res = quotient * 2;

    //@ assert remainder >= 0 && remainder <= 10;
    if (remainder > 0 && remainder < 7) {
        res += 1;
    } else if (remainder >= 7) {
        res += 2;
    }

    //@ assert res >= ((((x)) / 11) * 2);
    //@ assert res <= ((((x)) / 11) * 2 + 2);
    return res;
}

#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000);
    ensures \result == ((input) / 2 + ((input) % 2 + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t input)
{
    uint32_t half;
    uint32_t remainder;
    uint32_t increment;
    uint32_t result;

    half = input / 2;
    remainder = input % 2;

    //@ assert half == input / 2;
    //@ assert remainder == input % 2;

    //@ assert 0 <= remainder <= 1;
    if (remainder == 0) {
        increment = 0;
    } else {
        increment = 1;
    }

    result = half + increment;
    //@ assert result == ((input) / 2 + ((input) % 2 + 1) / 2);
    return result;
}

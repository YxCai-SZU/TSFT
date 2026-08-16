#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((((x)) / 2) + (((x)) % 2));
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t half;
    uint32_t remainder;
    int32_t result;

    half = x / 2;
    remainder = x % 2;

    //@ assert half == x / 2;
    //@ assert remainder == x % 2;

    result = (int32_t)(half + remainder);
    return result;
}

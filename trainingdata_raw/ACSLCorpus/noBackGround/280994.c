#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures (((((x)) / 11) * 2) <= (\result) <= ((((x)) / 11) * 2) + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result;
    uint64_t reminder;

    result = (x / 11) * 2;
    reminder = x % 11;

    if (reminder > 6)
    {
        result += 2;
    }
    else
    {
        result += 1;
    }

    //@ assert result >= (x / 11) * 2;
    //@ assert result <= (x / 11) * 2 + 2;

    return result;
}

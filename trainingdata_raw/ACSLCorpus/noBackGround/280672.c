#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result >= 0;
    ensures \result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
*/
int32_t func(uint32_t x)
{
    uint32_t div_part;
    uint32_t mod_part;
    uint32_t result;

    // Variable declarations at top
    div_part = x / 500;
    mod_part = (x % 500) / 5;
    result = 1000 * div_part + 5 * mod_part;

    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);

    return (int32_t)result;
}

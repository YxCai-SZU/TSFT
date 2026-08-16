#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t res;
    uint64_t temp_x;

    res = 0;
    temp_x = x / 500;
    res = res + temp_x * 1000;
    temp_x = (x % 500) / 5;
    res = res + temp_x * 5;

    //@ assert res == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return res;
}

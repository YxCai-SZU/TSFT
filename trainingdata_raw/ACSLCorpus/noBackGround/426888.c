#include <stdint.h>
/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 500 * 1000) + ((x) % 500 / 5 * 5));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ret;
    //@ assert (0 <= (x) && (x) <= 1000000000);
    ret = (x / 500 * 1000) + (x % 500 / 5 * 5);
    //@ assert ret == (((x) / 500 * 1000) + ((x) % 500 / 5 * 5));
    return ret;
}

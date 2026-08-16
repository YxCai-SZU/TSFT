#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x / 100 * 100) <= x;
    ensures \result == 0 ==> (x / 100 * 100) > x;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    //@ assert x / 100 * 100 <= x || x / 100 * 100 > x;
    if ((x / 100 * 100) <= x) {
        return 1;
    } else {
        return 0;
    }
}

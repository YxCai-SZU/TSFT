#include <stdint.h>

/*@
    requires ((x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result;
    //@ assert ((x) <= 1);
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    //@ assert result == (1 - (x));
    return result;
}


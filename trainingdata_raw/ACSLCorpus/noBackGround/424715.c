#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100000000000000 &&
        0 <= (b) && (b) <= 100000000000000 &&
        (a) + (b) <= 100000000000000);
    ensures \result == ((a) + (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert (0 <= (a) && (a) <= 100000000000000 &&         0 <= (b) && (b) <= 100000000000000 &&         (a) + (b) <= 100000000000000);
    //@ assert a + b <= 100000000000000;
    return a + b;
}

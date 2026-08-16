#include <stdint.h>

/*@
    requires (0 <= (a) <= (b) <= 1000000000000000000);
    requires (1 <= (x) <= 1000000000000000000);
    ensures \result <= ((b) / (x)) - ((a) / (x)) + 1;
    ensures \result >= ((b) / (x)) - ((a) / (x));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    uint64_t extra;

    //@ assert b >= a;
    //@ assert x > 0;
    //@ assert ((b) / (x)) >= ((a) / (x));

    if (a % x == 0) {
        extra = 1;
        //@ assert extra == 1;
    } else {
        extra = 0;
        //@ assert extra == 0;
    }

    //@ assert extra <= 1;

    return b / x - a / x + extra;
}

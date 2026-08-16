#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    uint64_t xx;
    uint64_t yy;
    uint64_t res;

    //@ assert 1 <= x <= 100000;
    //@ assert 1 <= y <= 100000;
    //@ assert 1 <= z <= 100000;
    //@ assert y + 2 * z <= x;

    xx = x - z;
    yy = y + z;

    //@ assert 0 <= xx <= 100000;
    //@ assert 1 <= yy <= 200000;
    //@ assert xx / yy <= 100000;

    res = xx / yy;
    //@ assert res == (((x) - (z)) / ((y) + (z)));
    return res;
}

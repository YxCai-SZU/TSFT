#include <stdint.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + (y) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations
    uint32_t ans;

    // Precondition assertions
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert y % 2 == 0;

    // Overflow safety
    //@ assert x + y / 2 <= 200;

    ans = x + y / 2;

    // Postcondition verification
    //@ assert ans == ((x) + (y) / 2);
    //@ assert 1 <= ans <= 200;

    return ans;
}

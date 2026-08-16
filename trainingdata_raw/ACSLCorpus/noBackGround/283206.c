#include <stdint.h>

/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result <= (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    uint64_t ans;

    //@ assert (1 <= (x) && 1 <= (y) && 1 <= (z) &&         (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&         (y) + 2 * (z) <= (x));
    
    if ((x - z) / (y + z) < 0)
    {
        ans = 0;
    }
    else
    {
        ans = (x - z) / (y + z);
    }

    //@ assert ans == (((x) - (z)) / ((y) + (z))) || ans == 0;
    //@ assert (((x) - (z)) / ((y) + (z))) < 0 || (((x) - (z)) / ((y) + (z))) == ans;
    //@ assert ans <= (((x) - (z)) / ((y) + (z)));

    return ans;
}

#include <stdint.h>

/*@
    requires (1 <= (X) && (X) <= 100 &&
        1 <= (Y) && (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == ((X) + (Y) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t X, uint32_t Y)
{
    uint32_t ans;
    //@ assert (1 <= (X) && (X) <= 100 &&         1 <= (Y) && (Y) <= 100 &&         (Y) % 2 == 0);
    ans = X + Y / 2;
    //@ assert ans == ((X) + (Y) / 2);
    return ans;
}

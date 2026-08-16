#include <stdint.h>

/*@
    requires (1 <= (X) <= 100 &&
        1 <= (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == ((X) + (Y) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t X, uint64_t Y)
{
    uint64_t ans;

    //@ assert X + Y / 2 <= 150;
    ans = X + Y / 2;
    return ans;
}

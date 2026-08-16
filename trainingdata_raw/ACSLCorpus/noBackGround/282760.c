#include <stdint.h>

/*@
    requires (0 <= (r) && (r) <= 400 &&
        0 <= (g) && (g) <= 400 &&
        (r) < (g));
    ensures \result == (((g) - (r)) * 2);
    assigns \nothing;
*/
int64_t func(int64_t r, int64_t g)
{
    int64_t ans;
    //@ assert (0 <= (r) && (r) <= 400 &&         0 <= (g) && (g) <= 400 &&         (r) < (g));
    ans = (g - r) * 2;
    //@ assert ans == (((g) - (r)) * 2);
    return ans;
}

#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 0 <= r <= 4500;
    predicate g_in_range(integer g) = 0 <= g <= 4500;
    logic integer func_spec(integer r, integer g) = 2 * g - r;
*/


int64_t func(int64_t r, int64_t g)
{
    int64_t ans;
    //@ assert -4500 <= 2 * g - r <= 9000;
    ans = 2 * g - r;
    return ans;
}

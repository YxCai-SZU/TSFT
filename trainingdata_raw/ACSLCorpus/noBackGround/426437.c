#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    assigns \nothing;
    ensures \result == (180 * (n) - 360);
*/
int64_t func(int64_t n)
{
    int64_t sum_interior_angles;
    //@ assert (3 <= (n) && (n) <= 100);
    sum_interior_angles = 180 * n - 360;
    //@ assert sum_interior_angles == (180 * (n) - 360);
    return sum_interior_angles;
}

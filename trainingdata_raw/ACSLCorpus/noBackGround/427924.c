#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (d) <= 10000 && 1 <= (s) <= 10000);
    ensures \result == ((n) * (d));
    assigns \nothing;
*/
int32_t total_distance_before_collision(int32_t n, int32_t d, int32_t s)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert (1 <= (n) <= 100 && 1 <= (d) <= 10000 && 1 <= (s) <= 10000);
    //@ assert ((n) * (d)) <= 100 * 10000;

    result = n * d;
    //@ assert result == ((n) * (d));
    return result;
}

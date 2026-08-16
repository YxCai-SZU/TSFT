#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires (0 <= (k) && (k) <= 23 * 60 + 59);
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2)) - k;
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    assigns \nothing;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k)
{
    int32_t start_minutes;
    int32_t end_minutes;
    int32_t ans;

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;

    //@ assert end_minutes - start_minutes >= 0;
    //@ assert end_minutes - start_minutes <= 23 * 60 + 59;

    ans = end_minutes - start_minutes - k;

    //@ assert ans >= 0;
    //@ assert ans <= 23 * 60 + 59;

    return ans;
}

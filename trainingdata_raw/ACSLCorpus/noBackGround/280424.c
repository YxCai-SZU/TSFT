#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        (a) * (b) <= 9223372036854775807 &&
        (a) * (b) >= -9223372036854775808);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         (a) * (b) <= 9223372036854775807 &&         (a) * (b) >= -9223372036854775808);
    ans = a * b;
    //@ assert ans == ((a) * (b));
    return ans;
}

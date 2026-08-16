#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t result;

    pi_approx = 3;
    result = 2 * r * pi_approx;

    //@ assert result == 2 * r * 3;

    return result;
}

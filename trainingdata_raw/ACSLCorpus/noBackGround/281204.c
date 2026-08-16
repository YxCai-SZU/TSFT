#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t pi_approx;
    int32_t circumference;

    pi_approx = 3;
    //@ assert pi_approx == 3;

    circumference = 2 * r * pi_approx;
    //@ assert circumference == 2 * r * 3;

    //@ assert circumference >= 2 * 1 * 3;
    //@ assert circumference <= 2 * 100 * 3;

    return circumference;
}

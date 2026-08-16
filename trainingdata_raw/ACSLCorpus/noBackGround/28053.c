#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t ans;

    pi_approx = 3;

    //@ assert pi_approx == 3;
    //@ assert (1 <= (r) <= 100);

    //@ assert pi_approx * r * r >= 0;
    //@ assert pi_approx * r * r <= 30000;

    ans = pi_approx * r * r;

    //@ assert ans == 3 * r * r;
    //@ assert ans == (3 * (r) * (r));

    return ans;
}

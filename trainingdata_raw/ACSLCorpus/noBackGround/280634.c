#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t ans;

    //@ assert (1 <= (r) <= 100);
    ans = 1;
    ans *= 3;
    //@ assert ans == 3 * 1;

    //@ assert 3 <= 3 * r;
    //@ assert 3 * r <= 3 * 100;
    ans *= r;
    //@ assert ans == 3 * r;

    //@ assert 3 * r * r <= 3 * 100 * 100;
    ans *= r;
    //@ assert ans == 3 * r * r;

    return ans;
}

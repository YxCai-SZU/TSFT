#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi_approx;
    pi_approx = 3;
    //@ assert pi_approx == 3;
    return r * 2 * pi_approx;
}

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * 2 * 3);
    assigns \nothing;
*/
int32_t func2(int32_t a)
{
    int32_t pi_approx;
    pi_approx = 3;
    //@ assert pi_approx == 3;
    return a * 2 * pi_approx;
}

/*@
    requires (1 <= (s) <= 100);
    ensures \result == ((s) * 3 * 3);
    assigns \nothing;
*/
int32_t func3(int32_t s)
{
    int32_t pi_approx;
    pi_approx = 3;
    //@ assert pi_approx == 3;
    return s * 3 * pi_approx;
}

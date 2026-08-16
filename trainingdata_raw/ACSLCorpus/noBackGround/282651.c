#include <stdint.h>

/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) && 1 <= (n) && (x) + (y) + (z) >= (n));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y, int64_t z, int64_t n)
{
    int64_t n_mut;
    int64_t result;
    int64_t x_min;
    int64_t y_min;
    int64_t z_min;

    n_mut = n;
    result = 0;

    //@ assert n_mut == n && result == 0;

    x_min = x < n_mut ? x : n_mut;
    result += x_min;
    n_mut -= x_min;

    //@ assert result >= 0 && result <= n;

    y_min = y < n_mut ? y : n_mut;
    n_mut -= y_min;

    //@ assert n_mut >= 0;

    z_min = z < n_mut ? z : n_mut;
    n_mut -= z_min;

    //@ assert n_mut >= 0;

    result -= n_mut;

    //@ assert result >= 0;
    //@ assert result <= n;

    return result;
}

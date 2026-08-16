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
    int64_t pi;
    int64_t area;

    pi = 3;

    //@ assert pi == 3;
    //@ assert (1 <= (r) <= 100);
    //@ assert pi * r * r == 3 * r * r;

    //@ assert 0 <= pi * r * r <= 3 * 100 * 100;

    area = pi * r * r;

    //@ assert area >= 0;
    //@ assert area == 3 * r * r;

    return area;
}

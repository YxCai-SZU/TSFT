#include <stddef.h>

/*@
    requires (0 <= (n) <= 100) && (0 <= (m) <= 100);
    requires (2 <= (n) + (m));
    ensures \result == (((n) * ((n) - 1)) / 2) + (((m) * ((m) - 1)) / 2);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t t;
    size_t u;
    size_t result;

    //@ assert n * (n - 1) <= 100 * 99;
    //@ assert m * (m - 1) <= 100 * 99;

    if (n > 0) {
        t = (n * (n - 1)) / 2;
    } else {
        t = 0;
    }

    if (m > 0) {
        u = (m * (m - 1)) / 2;
    } else {
        u = 0;
    }

    result = t + u;
    return result;
}

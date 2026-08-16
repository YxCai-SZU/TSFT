#include <stddef.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result == (((n) + 2 * (d)) / (2 * (d) + 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t d) {
    // Variable declarations at scope top
    size_t res;

    //@ assert (1 <= (n) <= 20 && 1 <= (d) <= 20);
    //@ assert 1 <= n + 2 * d <= 60;
    //@ assert 1 <= 2 * d + 1 <= 41;

    res = (n + 2 * d) / (2 * d + 1);
    //@ assert res == (((n) + 2 * (d)) / (2 * (d) + 1));
    return res;
}

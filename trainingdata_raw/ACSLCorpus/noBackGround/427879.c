#include <stddef.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result >= 1;
    ensures \result == (((n) - 1) / (2 * (d) + 1) + 1);
    assigns \nothing;
*/
size_t func(size_t n, size_t d) {
    // Variable declarations at top of scope
    size_t ans;

    //@ assert n >= 1 && n <= 20;
    //@ assert d >= 1 && d <= 20;
    //@ assert 2 * d + 1 >= 3;
    //@ assert (n - 1) / (2 * d + 1) + 1 >= 1;

    ans = (n - 1) / (2 * d + 1) + 1;
    return ans;
}

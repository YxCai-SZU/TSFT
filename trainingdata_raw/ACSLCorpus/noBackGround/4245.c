#include <stddef.h>

/*@
    requires (1 <= (i) && (i) <= (n) && (n) <= 100);
    ensures \result >= 1 && \result <= n;
    ensures \result == n - i + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t i) {
    // Variable declarations at scope top
    size_t j;

    //@ assert n >= 1;
    //@ assert i >= 1;
    //@ assert n - i + 1 >= 1;

    j = n - i + 1;
    return j;
}

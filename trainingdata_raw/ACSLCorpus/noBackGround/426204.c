#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    // Variable declarations at scope top
    size_t ret;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 10000;

    ret = a * b;
    return ret;
}

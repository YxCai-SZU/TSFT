#include <stdbool.h>
/*@
    requires (1 <= (p) <= 100);
    requires (1 <= (q) <= 100);
    requires (1 <= (r) <= 100);
    ensures \result == p+q || \result == q+r || \result == p+r;
    ensures \result <= p+q+q+r;
*/
unsigned int func(unsigned int p, unsigned int q, unsigned int r) {
    unsigned int min1;
    unsigned int min2;

    //@ assert (1 <= (p) <= 100);
    //@ assert (1 <= (q) <= 100);
    //@ assert (1 <= (r) <= 100);

    if (p + q < q + r) {
        min1 = p + q;
    } else {
        min1 = q + r;
    }

    //@ assert min1 == p+q || min1 == q+r;

    if (min1 < p + r) {
        min2 = min1;
    } else {
        min2 = p + r;
    }

    //@ assert min2 == p+q || min2 == q+r || min2 == p+r;
    //@ assert min2 <= p+q+q+r;

    return min2;
}

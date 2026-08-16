#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures 1 <= \result <= 100000000000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t sa;
    int64_t sc;
    int64_t result;

    // Precondition verification
    //@ assert 1 <= ((a) * (b)) <= 100000000;
    //@ assert 1 <= ((c) * (d)) <= 100000000;

    sa = a * b;
    sc = c * d;

    //@ assert sa >= 1 && sa <= 100000000000;
    //@ assert sc >= 1 && sc <= 100000000000;

    if (sa > sc) {
        result = sa;
    } else {
        result = sc;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    return result;
}

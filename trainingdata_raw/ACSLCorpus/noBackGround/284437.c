#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result == (1000 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result = 0;
    uint32_t i = 0;

    //@ ghost uint32_t old_m = m;
    //@ ghost uint32_t old_n = n;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant result == 1900 * (int32_t)i;
        loop invariant (1 <= (old_n) <= 100 &&
        1 <= (old_m) <= (old_n) &&
        (old_m) <= 5);
        loop assigns i, result;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert i < m;
        result += 1900;
        i += 1;
    }

    i = 0;
    uint32_t limit = n - m;

    /*@
        loop invariant 0 <= i <= limit;
        loop invariant result == 1900 * (int32_t)old_m + 1000 * (int32_t)i;
        loop invariant (1 <= (old_n) <= 100 &&
        1 <= (old_m) <= (old_n) &&
        (old_m) <= 5);
        loop assigns i, result;
        loop variant limit - i;
    */
    while (i < limit) {
        //@ assert i < limit;
        result += 1000;
        i += 1;
    }

    //@ assert result == (1000 * ((old_n) - (old_m)) + 1900 * (old_m));
    return result;
}

#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= 100);
    ensures \result >= 0 && \result <= 1;
    assigns \nothing;
*/
int func(size_t n, size_t k) {
    int result = 0;
    size_t a = 7 % k;
    size_t i = 1;

    /*@
        loop invariant 1 <= i && i <= n;
        loop invariant a < k;
        loop invariant result >= 0 && result <= 1;
        loop assigns a, i, result;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert a < k;
        if (a == 0) {
            result = 1;
            break;
        }
        a = (10 * a + 7) % k;
        i = i + 1;
    }

    if (a == 0) {
        result = 1;
    }

    //@ assert result >= 0 && result <= 1;
    return result;
}

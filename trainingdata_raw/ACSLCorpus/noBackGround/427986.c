#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result <= a * b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t cnt = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= b;
        loop invariant ((cnt) <= (i));
        loop assigns i, cnt;
        loop variant b - i;
    */
    while (i < b) {
        if (i * 2 + 1 <= a) {
            cnt += 1;
        }
        i += 1;
    }

    //@ assert cnt <= a * b;
    return cnt;
}

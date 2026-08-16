#include <stdint.h>

/*@
    requires (1 <= (X) <= 100000);
    requires X == (int32_t)X;
    ensures \result == 0 || \result == 1;
*/
int32_t func(int64_t X) {
    int64_t i = 0;
    int64_t j = 0;
    int32_t result = 0;
    int64_t x = X;

    /*@
        loop invariant (1 <= (X) <= 100000);
        loop invariant 0 <= x;
        loop invariant x == X - 105 * i;
        loop assigns x, i;
    */
    while (x >= 105) {
        x -= 105;
        i += 1;
    }

    /*@
        loop invariant (1 <= (X) <= 100000);
        loop invariant 0 <= x;
        loop invariant x == ((X) - 105 * (i) - 15 * (j));
        loop invariant 0 <= i;
        loop invariant 0 <= j;
        loop assigns x, j;
    */
    while (x >= 15) {
        x -= 15;
        j += 1;
    }

    if (x == 0) {
        result = 1;
    } else if (i == 0 && j == 0) {
        result = 0;
    } else if (i >= j) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

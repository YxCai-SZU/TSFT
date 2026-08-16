#include <stddef.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    requires a != b;
    ensures (1 <= (\result) <= 3);
    ensures \result != a && \result != b;
*/
size_t func(size_t a, size_t b) {
    size_t sum;
    size_t result;

    sum = a + b;

    if (sum == 3) {
        //@ assert sum == 3;
        result = 3;
    } else if (sum == 5) {
        //@ assert sum == 5;
        result = 1;
    } else {
        //@ assert sum == 4;
        result = 2;
    }

    return result;
}

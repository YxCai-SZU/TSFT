#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == 0 || \result == 1 || \result == -1;
    ensures \result == 0 ==> (a * 2 < b * 5);
    ensures \result == 1 ==> (a * 2 == b * 5);
    ensures \result == -1 ==> (a * 2 > b * 5);
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t x;
    uint32_t y;
    int32_t result;

    x = a * 2;
    y = b * 5;

    if (x < y) {
        //@ assert x < y;
        result = 0;
    } else if (x == y) {
        //@ assert x == y;
        result = 1;
    } else {
        //@ assert x > y;
        result = -1;
    }

    return result;
}

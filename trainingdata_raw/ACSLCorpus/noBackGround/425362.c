#include <stdint.h>

/*@
    requires (1 <= (a) <= 12 && 1 <= (b) <= 31);
    ensures ((a) <= 8 || (b) < 10) ==> \result == 1;
    ensures ((a) > 8 && (b) >= 10) ==> \result == 0;
*/
int32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    int32_t result;

    if (a <= 8) {
        //@ assert ((a) <= 8 || (b) < 10);
        result = 1;
    } else if (b >= 10) {
        //@ assert ((a) > 8 && (b) >= 10);
        result = 0;
    } else {
        //@ assert ((a) <= 8 || (b) < 10);
        result = 1;
    }

    return result;
}

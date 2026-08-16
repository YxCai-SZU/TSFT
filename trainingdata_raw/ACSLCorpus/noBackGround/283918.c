#include <stdint.h>

/*@ requires (1 <= (n) <= 20 &&
     1 <= (a) <= 100 &&
     1 <= (b) <= 2000);
    ensures \result <= b;
    ensures \result == ((a) * (n)) || \result == b;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert (1 <= (n) <= 20 &&      1 <= (a) <= 100 &&      1 <= (b) <= 2000);
    //@ assert ((a) * (n)) <= 2000;

    if (a * n < b) {
        result = a * n;
    } else {
        result = b;
    }

    //@ assert result <= b;
    //@ assert result == ((a) * (n)) || result == b;
    return result;
}

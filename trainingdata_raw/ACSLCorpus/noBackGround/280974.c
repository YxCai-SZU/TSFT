#include <stdint.h>

/*@
    requires 0 <= a && a <= 100000000000000;
    requires 0 <= b && b <= 100000000000000;
    ensures \result == a + b;
    ensures \result >= a;
    ensures \result >= b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b) {
    //@ assert a + b <= 200000000000000;
    uint64_t sum = a + b;
    return sum;
}

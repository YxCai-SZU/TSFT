#include <stdint.h>

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;

    //@ assert a + b <= 200;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b;
    //@ assert a * b >= a;
    //@ assert a * b >= b;

    result = a * b - a - b + 1;

    //@ assert result > 0;
    return result;
}

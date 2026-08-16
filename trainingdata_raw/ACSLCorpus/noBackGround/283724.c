#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t a_minus_1;
    uint32_t b_minus_1;
    int32_t result;

    // Declare all variables at the top
    a_minus_1 = (a == 2) ? 1 : (a - 1);
    b_minus_1 = (b == 2) ? 1 : (b - 1);

    //@ assert a > 1 && a <= 100;
    //@ assert b > 1 && b <= 100;
    //@ assert a + b >= 2;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;

    result = (int32_t)(a * b - (a + b - 1));
    return result;
}

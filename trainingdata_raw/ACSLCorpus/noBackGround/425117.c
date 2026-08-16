#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    assigns \nothing;
    ensures ((\result) == (6 - ((a)) - ((b))) &&
        1 <= (\result) && (\result) <= 3 &&
        (\result) != (a) && (\result) != (b));
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 3 &&         1 <= (b) && (b) <= 3 &&         (a) != (b));
    result = 6 - a - b;
    //@ assert result == (6 - (a) - (b));
    //@ assert 1 <= result && result <= 3;
    //@ assert result != a && result != b;
    return result;
}

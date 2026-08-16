#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (a < 10 && b < 10 ==> \result == a * b) &&
            (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_value;
    uint32_t min_value;
    int32_t result;

    if (a > b) {
        max_value = a;
        min_value = b;
    } else {
        max_value = b;
        min_value = a;
    }

    if (max_value < 10) {
        //@ assert 1 <= max_value <= 10;
        //@ assert 1 <= min_value <= 10;
        //@ assert max_value * min_value <= 100;
        result = (int32_t)(max_value * min_value);
    } else {
        result = -1;
    }

    return result;
}

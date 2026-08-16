#include <stdint.h>

/*@ requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (((a) < 10 && (b) < 10) ==> \result == (int32_t)(a * b)) &&
            (((a) >= 10 || (b) >= 10) ==> \result == -1);
 */
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    uint32_t local_a = a;
    uint32_t local_b = b;

    //@ assert ((local_a) * (local_b)) <= 400;

    if (local_a < 10 && local_b < 10) {
        result = (int32_t)(local_a * local_b);
    } else {
        result = -1;
    }

    return result;
}

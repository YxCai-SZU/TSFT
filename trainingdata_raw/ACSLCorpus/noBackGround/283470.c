#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result == -1 || \result == (int)(a + b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    uint32_t local_a = a;
    uint32_t local_b = b;

    result = local_a + local_b;

    if (result < 10) {
        //@ assert result < 10;
        return -1;
    } else {
        //@ assert result == local_a + local_b;
        return (int32_t)result;
    }
}

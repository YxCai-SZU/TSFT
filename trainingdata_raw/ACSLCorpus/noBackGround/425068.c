#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (H) && (H) <= 100 &&
        (H) % 2 == 0);
    ensures \result == (((A) + (B)) * (H) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t H) {
    //@ assert A + B <= 200;
    //@ assert (A + B) * H <= 20000;
    //@ assert (A + B) * H / 2 <= 10000;
    return (A + B) * H / 2;
}

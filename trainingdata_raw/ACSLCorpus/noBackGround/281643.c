#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (H) && (H) <= 100 &&
        (H) % 2 == 0);
    ensures \result == (((A) + (B)) * (H) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t B, uint64_t H)
{
    //@ assert 2 <= A + B && A + B <= 200;
    //@ assert 2 <= (A + B) * H && (A + B) * H <= 20000;
    return (A + B) * H / 2;
}

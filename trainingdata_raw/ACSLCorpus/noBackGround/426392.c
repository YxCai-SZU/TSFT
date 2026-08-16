#include <stdint.h>

/*@
    requires (1 <= (A) <= 100 &&
        1 <= (B) <= 100 &&
        1 <= (H) <= 100 &&
        (H) % 2 == 0);
    ensures \result == (((A) + (B)) * (H) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t B, uint64_t H)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 2 <= A + B <= 200;
    //@ assert 2 <= (A + B) * H <= 20000;

    result = (A + B) * H / 2;
    //@ assert result == (((A) + (B)) * (H) / 2);
    return result;
}

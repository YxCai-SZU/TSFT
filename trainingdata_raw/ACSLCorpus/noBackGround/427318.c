#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 3 &&
        1 <= (B) && (B) <= 3 &&
        (A) != (B));
    ensures \result == (6 - (A) - (B));
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t B)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 0 <= 6 - A - B <= 6;
    result = 6 - A - B;
    //@ assert result == (6 - (A) - (B));
    return result;
}

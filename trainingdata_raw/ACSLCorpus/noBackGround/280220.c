#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    ensures \result <= p + (a * 3) / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t p)
{
    uint64_t result;
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    result = (a * 3 + p) / 2;
    //@ assert result == (((a) * 3 + (p)) / 2);
    //@ assert result <= p + (a * 3) / 2;
    return result;
}

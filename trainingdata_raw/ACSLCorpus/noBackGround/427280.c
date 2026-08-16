#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a > 9 || b > 9) ==> \result == -1;
    ensures (a <= 9 && b <= 9) ==> \result == (int)(a * b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    //@ assert a * b <= 400;

    if (a > 9 || b > 9) {
        result = -1;
    } else {
        result = (int32_t)(a * b);
    }

    return result;
}

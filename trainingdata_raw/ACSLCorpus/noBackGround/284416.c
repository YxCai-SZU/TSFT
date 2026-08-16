#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result == ((3 * (A) + (P)) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t ans;

    //@ assert (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    //@ assert 3 * A + P <= 400;

    ans = (3 * A + P) / 2;

    //@ assert ans == ((3 * (A) + (P)) / 2);

    return ans;
}

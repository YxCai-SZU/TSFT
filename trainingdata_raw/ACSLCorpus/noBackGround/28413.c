#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + c || \result == a + d || \result == b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t ans;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;

    //@ assert min_ab == ((a) < (b) ? (a) : (b));
    //@ assert min_cd == ((c) < (d) ? (c) : (d));

    ans = min_ab + min_cd;

    //@ assert ans == a + c || ans == b + c || ans == a + d || ans == b + d;

    return ans;
}

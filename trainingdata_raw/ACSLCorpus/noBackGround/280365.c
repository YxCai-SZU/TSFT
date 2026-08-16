#include <stdint.h>

/*@
    requires (1 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    ensures \result == (((e) - (a) + 1) * ((e) - (a) + 1) * ((e) - (a) + 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t ans;

    //@ assert 1 <= (e - a + 1) <= 123;
    ans = (e - a + 1) * (e - a + 1) * (e - a + 1);
    return ans;
}

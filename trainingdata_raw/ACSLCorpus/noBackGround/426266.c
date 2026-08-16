#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == ((a) + (b) + 1 <= (c) ? (a) + (b) + 1 + (b) : (b) + (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min_val;
    uint32_t ans;

    //@ assert a + b + 1 <= 201;
    //@ assert a + b + 1 + b <= 301;
    //@ assert b + c <= 200;

    if (a + b + 1 < c) {
        min_val = a + b + 1;
    } else {
        min_val = c;
    }

    ans = b + min_val;
    return ans;
}

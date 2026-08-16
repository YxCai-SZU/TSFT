#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max1;
    uint32_t max2;
    uint32_t ans;

    //@ assert a + c <= 4294967295;
    //@ assert a + d <= 4294967295;
    //@ assert b + c <= 4294967295;
    //@ assert b + d <= 4294967295;

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }

    ans = max1 + max2;
    return ans;
}

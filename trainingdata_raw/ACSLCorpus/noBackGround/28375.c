#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t x;
    uint32_t y;
    int32_t ans;

    //@ assert a * b <= 10000;
    //@ assert a + b - 1 <= 199;
    //@ assert a * b >= a + b - 1;
    //@ assert a * b - (a + b - 1) <= 9801;

    x = a * b;
    y = a + b - 1;
    ans = (int32_t)x - (int32_t)y;

    //@ assert ans == (int32_t)(a * b) - (int32_t)(a + b - 1);
    return ans;
}

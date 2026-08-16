#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b >= 0;
    //@ assert a * b - a - b + 1 > 0;
    //@ assert a * b <= 100 * 100;
    //@ assert a + b <= 100 + 100;
    //@ assert a * b - a - b + 1 <= 100 * 100 - 100 - 100 + 1;

    ans = a * b - a - b + 1;
    //@ assert ans == ((a) * (b) - (a) - (b) + 1);
    //@ assert ans > 0;

    return ans;
}

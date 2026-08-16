#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t ans;

    a1 = a;
    //@ assert (1 <= (a1) && (a1) <= 10);
    //@ assert 1 <= a1 * a1 && a1 * a1 <= 100;
    a2 = a * a;
    //@ assert 1 <= a1 * a1 * a1 && a1 * a1 * a1 <= 1000;
    a3 = a * a * a;
    ans = a1 + a2 + a3;
    return ans;
}

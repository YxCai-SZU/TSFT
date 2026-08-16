#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    ensures \result <= ((a) + (b) + (c));
    ensures \result >= a + b || \result >= a + c || \result >= b + c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t ans;
    uint32_t tmp1;
    uint32_t tmp2;
    uint32_t tmp3;

    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    //@ assert ((a) + (b) + (c)) <= 300;

    ans = a + b + c;

    tmp1 = a + b;
    ans = (ans > tmp1) ? ans : tmp1;

    tmp2 = a + c;
    ans = (ans > tmp2) ? ans : tmp2;

    tmp3 = b + c;
    ans = (ans > tmp3) ? ans : tmp3;

    //@ assert ans <= ((a) + (b) + (c));
    return ans;
}

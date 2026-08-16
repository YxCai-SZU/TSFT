#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result <= c / a;
    ensures \result <= d / b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t ans;
    uint32_t min_val;
    uint32_t div_c_a;
    uint32_t div_d_b;

    //@ assert a > 0 && a <= 10000;
    //@ assert b > 0 && b <= 10000;
    //@ assert c > 0 && c <= 10000;
    //@ assert d > 0 && d <= 10000;

    div_c_a = c / a;
    div_d_b = d / b;

    //@ assert div_c_a <= 10000;
    //@ assert div_d_b <= 10000;

    if (div_c_a < div_d_b) {
        min_val = div_c_a;
    } else {
        min_val = div_d_b;
    }

    ans = min_val;

    //@ assert ans <= c / a;
    //@ assert ans <= d / b;

    return ans;
}

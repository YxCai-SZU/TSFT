#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result <= (a + c) * (b + d);
    ensures 0 <= \result;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_a;
    uint32_t min_c;
    uint32_t ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    min_a = a < b ? a : b;
    //@ assert min_a == ((a) < (b) ? (a) : (b));

    min_c = c < d ? c : d;
    //@ assert min_c == ((c) < (d) ? (c) : (d));

    //@ assert 0 <= min_a * min_c <= 10000;
    //@ assert min_a * min_c <= (a + c) * (b + d);

    ans = min_a * min_c;
    //@ assert ans == min_a * min_c;

    return ans;
}

#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res = 0;
    int64_t rst = k;
    int64_t min_a = 0;
    int64_t min_b = 0;
    int64_t min_c = 0;

    //@ assert 0 <= rst && rst == k;

    min_a = (a < rst) ? a : rst;
    //@ assert min_a <= a && min_a <= rst;
    res += min_a;
    rst -= min_a;

    //@ assert 0 <= rst && rst == k - min_a;

    min_b = (b < rst) ? b : rst;
    //@ assert min_b <= b && min_b <= rst;
    rst -= min_b;

    //@ assert 0 <= rst && rst == k - min_a - min_b;

    min_c = (c < rst) ? c : rst;
    //@ assert min_c <= c && min_c <= rst;
    rst -= min_c;

    //@ assert 0 <= rst && rst == k - min_a - min_b - min_c;

    res -= min_c;

    //@ assert res == min_a - min_c;
    //@ assert min_a <= k && min_c >= 0 ==> res <= k;

    return res;
}

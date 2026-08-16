#include <limits.h>

/*@
    requires (1 <= (a) <= 7 &&
        1 <= (b) <= 7 &&
        1 <= (c) <= 7 &&
        1 <= (k) <= 7 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= 0;
    ensures \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;
    int rst_a = a;
    int rst_b = b;
    int rst_c = c;
    int min_a;
    int min_b;
    int min_c;

    //@ assert (1 <= (a) <= 7 &&         1 <= (b) <= 7 &&         1 <= (c) <= 7 &&         1 <= (k) <= 7 &&         (a) + (b) + (c) >= (k));
    //@ assert rst >= 0 && rst_a >= 0 && rst_b >= 0 && rst_c >= 0;

    min_a = rst < rst_a ? rst : rst_a;
    ans += min_a;
    rst -= min_a;
    rst_a -= min_a;

    //@ assert min_a >= 0;
    //@ assert rst >= 0 && rst_a >= 0 && rst_b >= 0 && rst_c >= 0;

    min_b = rst < rst_b ? rst : rst_b;
    rst -= min_b;
    rst_b -= min_b;

    //@ assert min_b >= 0;
    //@ assert rst >= 0 && rst_a >= 0 && rst_b >= 0 && rst_c >= 0;

    min_c = rst < rst_c ? rst : rst_c;
    rst -= min_c;
    rst_c -= min_c;

    //@ assert min_c >= 0;
    //@ assert rst >= 0 && rst_a >= 0 && rst_b >= 0 && rst_c >= 0;

    ans -= rst;

    //@ assert ans >= 0;
    //@ assert ans <= k;

    return ans;
}

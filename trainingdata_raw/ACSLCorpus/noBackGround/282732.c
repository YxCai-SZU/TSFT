#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result <= a;
    ensures \result >= ((k) - ((a) + (b) + (c)) < 0 ? 0 : (k) - ((a) + (b) + (c)));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;
    int64_t rst;

    //@ assert (0 <= (a) && 0 <= (b) && 0 <= (c) &&         1 <= (k) && (k) <= (a) + (b) + (c) &&         (a) + (b) + (c) <= 2000000000);

    if (a < k) {
        ans = a;
    } else {
        ans = k;
    }

    rst = k - (a + b + c);
    if (rst < 0) {
        rst = 0;
    }

    ans = ans - rst;

    //@ assert ans <= a;
    //@ assert ans >= ((k) - ((a) + (b) + (c)) < 0 ? 0 : (k) - ((a) + (b) + (c)));

    return ans;
}

#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= k;
    ensures \result >= ((k) - ((a) + (b) + (c) - (k)));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans;
    int32_t max_val;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 &&         1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);

    if (a >= k) {
        ans = k;
    } else if (a + b >= k) {
        ans = a;
    } else {
        ans = a - (k - a - b);
    }

    //@ assert ans <= k;

    if (ans > k - (a + b + c - k)) {
        max_val = ans;
    } else {
        max_val = k - (a + b + c - k);
    }

    //@ assert max_val <= k;
    //@ assert max_val >= ((k) - ((a) + (b) + (c) - (k)));

    return max_val;
}

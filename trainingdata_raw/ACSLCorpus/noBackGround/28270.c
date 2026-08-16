#include <stdint.h>

/*@
    requires (1 <= (a) && 1 <= (b) && 1 <= (c) && 1 <= (k) &&
        (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result <= a + b + c && \result >= k - b - c;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans = 0;
    int32_t rest = k;

    // Use all the A cards we have
    if (rest <= a) {
        ans += rest;
        //@ assert ans <= a + b + c;
        return ans;
    }

    rest -= a;
    ans += a;

    // Use all the B cards we have
    if (rest <= b) {
        //@ assert ans <= a + b + c;
        return ans;
    }

    rest -= b;

    // Use all the C cards we have
    if (rest <= c) {
        //@ assert ans <= a + b + c;
        return ans;
    }

    ans -= (rest - c);

    //@ assert ans <= a + b + c;
    return ans;
}

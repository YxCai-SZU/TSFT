#include <stdint.h>
/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        (k) >= 1 &&
        (k) <= (a) + (b) + (b));
    ensures \result >= 0;
    ensures \result <= a + b;
    ensures \result == ((k) <= (a) ? (k) : (a) + ((k) - (a) <= (b) ? 0 : (k) - (a) - (b)));
*/
int64_t func(int64_t a, int64_t b, int64_t k)
{
    int64_t ans = 0;
    int64_t remaining_k = k;
    int64_t remaining_a = a;
    int64_t remaining_b = b;

    if (remaining_a >= remaining_k)
    {
        //@ assert remaining_k >= 0;
        //@ assert remaining_k <= a + b;
        return remaining_k;
    }

    ans += remaining_a;
    remaining_k -= remaining_a;

    remaining_b -= remaining_k;

    //@ assert remaining_b <= INT64_MAX;
    ans += (remaining_b < 0) ? -remaining_b : 0;

    //@ assert ans >= 0;
    //@ assert ans <= a + b;
    return ans;
}

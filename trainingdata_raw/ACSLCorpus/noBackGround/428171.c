#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&
        (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result >= -k;
    ensures \result <= k;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t max_sum = 0;
    int32_t remaining_k = k;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&         (k) <= (a) + (b) + (c) &&         (a) + (b) + (c) <= 2000000000);

    if (a >= remaining_k)
    {
        max_sum += remaining_k;
        remaining_k -= remaining_k;
    }
    else
    {
        max_sum += a;
        remaining_k -= a;
    }

    //@ assert max_sum == (a >= k ? k : a);
    //@ assert remaining_k == k - max_sum;

    if (b >= remaining_k)
    {
        remaining_k -= remaining_k;
    }
    else
    {
        remaining_k -= b;
    }

    //@ assert remaining_k == (b >= k - max_sum ? 0 : k - max_sum - b);

    max_sum -= remaining_k;

    //@ assert max_sum == (((a) >= (k) ? (k) : (a)) -          ((b) >= (k) - ((a) >= (k) ? (k) : (a)) ? 0 : (k) - ((a) >= (k) ? (k) : (a)) - (b)));
    //@ assert max_sum >= -k;
    //@ assert max_sum <= k;

    return max_sum;
}

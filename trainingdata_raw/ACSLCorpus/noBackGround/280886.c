#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000 &&
        1 <= (k) <= (a) + (b) + (c) &&
        (a) + (b) >= (k));
    ensures \result <= a;
    ensures \result >= 0;
    ensures \result == ((((a) < (k)) ? (a) : (k)) - ((k) - (((a) < (k)) ? (a) : (k)) - (((b) < ((k) - (((a) < (k)) ? (a) : (k)))) ? (b) : ((k) - (((a) < (k)) ? (a) : (k))))));
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t k_remaining;
    int32_t min_val;
    int32_t min_val_2;
    int32_t ans;

    k_remaining = k;

    //@ assert k_remaining == k;

    if (a < k_remaining) {
        min_val = a;
    } else {
        min_val = k_remaining;
    }

    k_remaining = k_remaining - min_val;

    //@ assert k_remaining >= 0;

    if (b < k_remaining) {
        min_val_2 = b;
    } else {
        min_val_2 = k_remaining;
    }

    k_remaining = k_remaining - min_val_2;

    //@ assert k_remaining >= 0;

    ans = min_val - k_remaining;

    //@ assert ans <= a;

    return ans;
}

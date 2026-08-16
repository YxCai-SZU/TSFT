#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0) && (1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= k;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t total = 0;
    int64_t k_remaining = k;
    int64_t use_a;
    int64_t use_b;
    int64_t use_c;

    if (a < k_remaining) {
        use_a = a;
    } else {
        use_a = k_remaining;
    }
    total += use_a;
    k_remaining -= use_a;

    if (b < k_remaining) {
        use_b = b;
    } else {
        use_b = k_remaining;
    }
    k_remaining -= use_b;

    if (c < k_remaining) {
        use_c = c;
    } else {
        use_c = k_remaining;
    }

    total -= use_c;

    //@ assert total <= k;

    return total;
}

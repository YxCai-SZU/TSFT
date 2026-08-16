#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000);
    ensures -c <= \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t sum = 0;
    int64_t k_remaining = k;

    //@ assert sum == 0 && k_remaining == k;

    if (a <= k_remaining) {
        sum += a;
        k_remaining -= a;
        //@ assert sum == a && k_remaining == k - a;
    } else {
        sum = k;
        //@ assert sum == k && k_remaining == k;
        //@ assert -c <= sum <= a;
        return sum;
    }

    if (k_remaining >= b) {
        k_remaining -= b;
        //@ assert k_remaining == k - a - b;
    } else {
        //@ assert -c <= sum <= a;
        return sum;
    }

    if (c <= k_remaining) {
        sum -= c;
        //@ assert sum == a - c;
    } else {
        sum -= k_remaining;
        //@ assert sum == a - (k - a - b);
    }

    //@ assert -c <= sum <= a;
    return sum;
}

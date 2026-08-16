#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t result = 0;
    int64_t first = 0;
    int64_t second = 0;
    int64_t third = 0;
    int64_t min_a_k;
    int64_t k_remaining;
    int64_t min_k_remaining_b;
    int64_t min_k_remaining_c;

    //@ assert a >= 0 && b >= 0 && c >= 0 && k >= 1 && k <= a + b + c && k <= 2000000000;

    if (a < k) {
        min_a_k = a;
    } else {
        min_a_k = k;
    }
    result += min_a_k;
    first = min_a_k;

    //@ assert k >= first;
    //@ assert k - first <= 2000000000;

    k_remaining = k - first;
    if (k_remaining < b) {
        min_k_remaining_b = k_remaining;
    } else {
        min_k_remaining_b = b;
    }
    k_remaining -= min_k_remaining_b;
    second = min_k_remaining_b;

    if (k_remaining < c) {
        min_k_remaining_c = k_remaining;
    } else {
        min_k_remaining_c = c;
    }
    k_remaining -= min_k_remaining_c;
    third = min_k_remaining_c;

    if (k_remaining > 0) {
        result -= k_remaining;
    }

    //@ assert result <= a;
    return result;
}

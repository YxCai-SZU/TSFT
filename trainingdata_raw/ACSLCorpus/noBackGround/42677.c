#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 && (k) <= (a) + (b) + (c));
    ensures ((\result) <= (k));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t sum;
    int64_t a_remaining;
    int64_t b_remaining;
    int64_t c_remaining;

    k_remaining = k;
    sum = 0;

    // Add cards from A
    //@ assert k_remaining >= 0;
    a_remaining = (a < k_remaining) ? a : k_remaining;
    sum += a_remaining;
    k_remaining -= a_remaining;

    // Subtract cards from B
    //@ assert k_remaining >= 0;
    b_remaining = (b < k_remaining) ? b : k_remaining;
    k_remaining -= b_remaining;

    // Add cards from C
    //@ assert k_remaining >= 0;
    c_remaining = (c < k_remaining) ? c : k_remaining;
    sum += c_remaining;

    //@ assert sum <= k;
    return sum;
}

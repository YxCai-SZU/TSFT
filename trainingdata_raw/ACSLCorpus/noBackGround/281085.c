#include <stdint.h>

/*@ requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    ensures \result >= 0;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t s;
    uint64_t ans;
    uint64_t r;

    if (m > 2 * n) {
        uint64_t rem = m - 2 * n;
        s = n + (rem / 4);
    } else if (m == 2 * n) {
        s = n;
    } else {
        s = m / 2;
    }

    if (n > m / 2) {
        ans = m / 2;
    } else {
        ans = n + (m - 2 * n) / 4;
    }

    if (s < ans) {
        r = s;
    } else {
        r = ans;
    }

    //@ assert r <= n + m / 2;
    //@ assert r >= 0;

    return r;
}

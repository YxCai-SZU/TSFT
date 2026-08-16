#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t ans;
    //@ assert (1 <= (k) <= (n) <= 50);
    ans = n - k + 1;
    //@ assert ans == ((n) - (k) + 1);
    return ans;
}

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= (n) &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int32_t func2(int32_t n, int32_t k, int32_t x, int32_t y)
{
    int32_t ans;
    //@ assert (1 <= (n) <= 10000 &&         1 <= (k) <= (n) &&         1 <= (y) < (x) <= 10000);
    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= n && n <= 10000;
    //@ assert k >= 1 && k <= n;
    //@ assert y >= 1 && y < x;
    //@ assert n * x <= 10000 * 10000;
    //@ assert k * x <= 10000 * 10000;
    //@ assert (n - k) * y <= 10000 * 10000;
    
    if (n <= k) {
        ans = n * x;
    } else {
        ans = k * x + (n - k) * y;
    }
    //@ assert ans == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    return ans;
}

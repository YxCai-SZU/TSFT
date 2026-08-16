#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result == ((n) < (m) / 2 + 1 ? (n) + ((m) - (n) * 2) / 4 : (m) / 2);
    ensures \result <= n + m / 2;
    ensures \result >= 0;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans = 0;
    uint64_t local_n = n;
    uint64_t local_m = m;

    if (local_n < local_m / 2 + 1)
    {
        ans += local_n;
        uint64_t rem = (local_m - local_n * 2) / 4;
        ans += rem;
        //@ assert ans == ((n) < (m) / 2 + 1 ? (n) + ((m) - (n) * 2) / 4 : (m) / 2);
    }
    else
    {
        ans += local_m / 2;
        //@ assert ans == ((n) < (m) / 2 + 1 ? (n) + ((m) - (n) * 2) / 4 : (m) / 2);
    }

    //@ assert ans <= n + m / 2;
    //@ assert ans >= 0;
    return ans;
}

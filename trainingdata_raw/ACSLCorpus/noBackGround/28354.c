#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert n * 2 <= 18446744073709551615;
    //@ assert m - n * 2 <= 18446744073709551615;
    //@ assert (m - n * 2) / 4 <= 4611686018427387903;
    //@ assert n + (m - n * 2) / 4 <= 18446744073709551615;

    if (n * 2 <= m) {
        ans = n + (m - n * 2) / 4;
    } else {
        ans = m / 2;
    }

    //@ assert ans <= n + m;
    return ans;
}

#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t min_val;
    uint64_t ans;

    //@ assert 1 <= n && 1 <= m;
    //@ assert n <= 1000000000000 && m <= 1000000000000;

    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }

    //@ assert min_val == (n < m ? n : m);

    if (2 * min_val < n + m) {
        //@ assert min_val >= 0;
        //@ assert n + m - 2 * min_val >= 0;
        //@ assert (n + m - 2 * min_val) / 4 <= n + m;
        ans = min_val + (n + m - 2 * min_val) / 4;
    } else {
        //@ assert n + m >= 0;
        //@ assert (n + m - 1) / 2 <= n + m;
        ans = (n + m - 1) / 2;
    }

    //@ assert ans >= 0;
    //@ assert ans <= n + m;
    return ans;
}

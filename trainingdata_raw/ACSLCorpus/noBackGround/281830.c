#include <stdint.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result >= 0;
    ensures \result == n * m - (n - 1) - m + 1;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Variable declarations at scope top
    int32_t ans;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    //@ assert n * m <= 400;
    //@ assert n * m - (n - 1) >= 0;
    //@ assert n * m - (n - 1) - m >= -19;
    //@ assert n * m - (n - 1) - m + 1 >= 0;

    ans = n * m - (n - 1) - m + 1;
    return ans;
}

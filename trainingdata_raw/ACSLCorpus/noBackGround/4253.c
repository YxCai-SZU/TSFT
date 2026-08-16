#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    requires (0 <= (white) && (white) <= (n) * (n));
    ensures \result == n * n - white;
    ensures ((\result) == (n) * (n) - (white) && (\result) >= 0);
*/
int32_t func(int32_t n, int32_t white)
{
    int32_t ans;
    //@ assert (0 <= (white) && (white) <= (n) * (n));
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 0 <= n * n <= 10000;
    ans = n * n - white;
    //@ assert ((ans) == (n) * (n) - (white) && (ans) >= 0);
    return ans;
}

#include <stdint.h>

/*@
    requires (1 <= (n) <= 200000 && 1 <= (k) <= (n));
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert n >= 1;
    //@ assert k >= 1;
    //@ assert n >= k;

    result = n - k + 1;
    return result;
}

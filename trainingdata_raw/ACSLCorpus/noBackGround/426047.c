#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result >= 0;
    ensures \result < 2;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t k)
{
    int32_t ans;
    uint32_t n_unsigned;
    uint32_t k_unsigned;
    uint32_t remainder;

    ans = 0;
    //@ assert ((ans) >= 0);

    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }

    if (k < 0) {
        k_unsigned = (uint32_t)(-k);
    } else {
        k_unsigned = (uint32_t)k;
    }

    remainder = n_unsigned % k_unsigned;

    if (remainder != 0) {
        ans = 1;
    }

    //@ assert ans < 2;
    return ans;
}

#include <stdint.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Variable declarations at scope top
    int32_t ans;

    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 9801;

    ans = (n - 1) * (m - 1);
    return ans;
}

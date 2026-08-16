#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= (a) * (a));
    ensures \result == a * a - b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= (a) * (a));
    //@ assert ((a) * (a) <= 10000);
    //@ assert a * a >= b;

    ans = a * a - b;
    return ans;
}

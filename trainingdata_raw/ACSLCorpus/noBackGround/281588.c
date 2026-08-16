#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at scope top
    bool ans;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    ans = (t * s >= d);
    return ans;
}

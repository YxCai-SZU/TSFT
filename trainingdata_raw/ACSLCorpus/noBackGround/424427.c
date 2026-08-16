#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (x <= 500 * k);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at scope top
    bool ans;

    //@ assert (500 * (k)) == 500 * k;
    ans = (x <= 500 * k);
    return ans;
}

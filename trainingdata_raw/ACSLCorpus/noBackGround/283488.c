#include <limits.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int func(int r, int g)
{
    // Variable declarations at scope top
    int ans;

    //@ assert (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    //@ assert 0 <= 2 * g <= 9000;
    //@ assert 2 * g - r <= 9000;
    //@ assert 2 * g - r >= -4500;

    ans = 2 * g - r;
    return ans;
}

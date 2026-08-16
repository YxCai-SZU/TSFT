#include <stdbool.h>

/*@
    requires (0 <= (x) && (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    //@ assert (0 <= (x) && (x) <= 1);
    ans = 1 - x;
    //@ assert ans == (1 - (x));
    return ans;
}

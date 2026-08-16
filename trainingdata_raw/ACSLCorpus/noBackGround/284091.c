#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (3) * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int ans;

    //@ assert 2 * pi * 1 <= 2 * pi * r;
    //@ assert 2 * pi * r <= 2 * 3 * 100;

    ans = 2 * pi * r;
    return ans;
}

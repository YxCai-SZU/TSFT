#include <limits.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == ((g) * 2 - (r));
    assigns \nothing;
*/
int func(int r, int g) {
    int ans;
    //@ assert 0 <= g <= 4500;
    //@ assert 0 <= r <= 4500;
    ans = g * 2 - r;
    //@ assert ans == ((g) * 2 - (r));
    return ans;
}

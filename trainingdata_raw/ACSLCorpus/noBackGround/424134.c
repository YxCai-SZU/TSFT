#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int func(int r) {
    int ans;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert r * r <= 10000;
    //@ assert 3 * r * r <= 30000;
    //@ assert 3 * r * r >= 3;
    
    ans = 3 * r * r;
    
    //@ assert ans == (3 * (r) * (r));
    return ans;
}

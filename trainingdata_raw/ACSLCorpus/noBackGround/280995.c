#include <limits.h>

/*@
    requires (0 <= (h1) && (h1) < 24 &&
        0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 &&
        0 <= (m2) && (m2) < 60);
    requires 0 <= k && k < 24*60;
    requires ((h1) * 60 + (m1) < (h2) * 60 + (m2));
    ensures \result >= 0;
    ensures \result <= (h2 * 60 + m2) - (h1 * 60 + m1);
    ensures \result == (h2 * 60 + m2) - (h1 * 60 + m1) - k || \result == 0;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int ans;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    
    //@ assert t1 < t2;
    
    if (t2 - t1 - k > 0) {
        ans = t2 - t1 - k;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= t2 - t1;
    //@ assert ans == t2 - t1 - k || ans == 0;
    
    return ans;
}

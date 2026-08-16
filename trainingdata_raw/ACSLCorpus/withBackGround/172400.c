#include <limits.h>

/*@
    predicate X_in_range(integer X) = 400 <= X && X < 2000;
    predicate ans_in_range(integer ans) = 0 <= ans && ans <= 8;
*/

/*@
    requires X_in_range(X);
    ensures ans_in_range(\result);
    assigns \nothing;
*/
int func(int X)
{
    int ans;
    ans = 8;
    
    //@ assert ans_in_range(ans);
    
    if (X >= 2000) {
        ans -= 1;
    } else if (X >= 1600) {
        ans -= 2;
    } else if (X >= 1200) {
        ans -= 3;
    } else if (X >= 800) {
        ans -= 4;
    }
    
    //@ assert ans_in_range(ans);
    
    return ans;
}

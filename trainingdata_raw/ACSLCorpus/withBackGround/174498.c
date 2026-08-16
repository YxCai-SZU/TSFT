#include <limits.h>

/*@
    predicate in_range(integer x) = 400 <= x && x < 2000;
    
    predicate ans_valid(integer a) = a == 8 || a == 7 || a == 6 || a == 5;
    
    predicate ans_implies(integer a, integer x) =
        (a == 8 ==> x < 600) &&
        (a == 7 ==> 600 <= x && x < 800) &&
        (a == 6 ==> 800 <= x && x < 1000) &&
        (a == 5 ==> 1000 <= x && x < 2000);
*/

/*@
    requires in_range(x);
    ensures ans_valid(\result);
    ensures ans_implies(\result, x);
*/
int func(int x)
{
    int ans;
    
    //@ assert in_range(x);
    
    if (x < 600) {
        ans = 8;
    } else if (x < 800) {
        ans = 7;
    } else if (x < 1000) {
        ans = 6;
    } else {
        ans = 5;
    }
    
    //@ assert ans_valid(ans);
    //@ assert ans_implies(ans, x);
    
    return ans;
}

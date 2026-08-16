#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer compute_ans(integer a, integer b) = a - b * 2;
    
    predicate ans_post(integer ans, integer a, integer b) =
        ans >= 0 && (ans == compute_ans(a, b) || ans == 0);
*/

/*@
    requires valid_range(a, b);
    ensures ans_post(\result, a, b);
*/
int func(int a, int b)
{
    int ans;
    
    ans = a - b * 2;
    
    if (ans > 0)
    {
        //@ assert ans == compute_ans(a, b);
        return ans;
    }
    else
    {
        //@ assert ans == compute_ans(a, b);
        return 0;
    }
}

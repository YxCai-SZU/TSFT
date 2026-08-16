#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;
    predicate ans_range(integer v) = 0 <= v <= 3;
    predicate result_range(integer v) = 1 <= v <= 3;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures result_range(\result);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    int result;
    
    //@ assert ans_range(ans);
    
    if (a == b) {
        ans += 1;
        //@ assert ans_range(ans);
    }
    //@ assert ans_range(ans);
    
    if (b == c) {
        ans += 1;
        //@ assert ans_range(ans);
    }
    //@ assert ans_range(ans);
    
    if (a == c) {
        ans += 1;
        //@ assert ans_range(ans);
    }
    //@ assert ans_range(ans);
    
    if (ans == 3) {
        result = 1;
        //@ assert result_range(result);
        return result;
    } else if (ans > 0) {
        result = 2;
        //@ assert result_range(result);
        return result;
    } else {
        result = 3;
        //@ assert result_range(result);
        return result;
    }
}

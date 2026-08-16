#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b) {
    int ans;
    int res;

    ans = a - 2 * b;
    
    if (ans > 0) {
        //@ assert ans > 0;
        res = ans;
    } else {
        //@ assert ans <= 0;
        res = 0;
    }
    
    return res;
}

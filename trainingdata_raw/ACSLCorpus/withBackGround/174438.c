#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate is_valid_r(integer r) = 0 <= r && r <= 4111;
*/

/*@
    requires is_valid_n(n) && is_valid_r(r);
    ensures (n < 10 ==> \result == 100 * (10 - n) + r);
    ensures (n >= 10 ==> \result == r);
    assigns \nothing;
*/
int func(int n, int r)
{
    int num;
    int ans;

    //@ assert is_valid_n(n) && is_valid_r(r);
    
    if (n < 10) {
        num = 100 * (10 - n);
        //@ assert num == 100 * (10 - n);
    } else {
        num = 0;
        //@ assert num == 0;
    }
    
    ans = num + r;
    
    //@ assert (n < 10 ==> ans == 100 * (10 - n) + r);
    //@ assert (n >= 10 ==> ans == r);
    
    return ans;
}

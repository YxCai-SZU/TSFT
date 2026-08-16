#include <limits.h>

/*@
    predicate valid_range(integer n, integer k) =
        1 <= n <= 10 && 1 <= k <= 10;

    predicate postcondition(integer n, integer k, integer ret) =
        (n > k ==> ret == 0) &&
        (n <= k ==> ret == k - n);
*/

/*@
    requires valid_range(n, k);
    ensures postcondition(n, k, \result);
    assigns \nothing;
*/
int func(int n, int k)
{
    int ans;

    //@ assert valid_range(n, k);
    
    if (n > k) {
        ans = 0;
    } else {
        //@ assert k >= n;
        //@ assert k - n <= 10;
        ans = k - n;
    }

    //@ assert postcondition(n, k, ans);
    return ans;
}

/*@
    requires valid_range(n, k);
    ensures postcondition(n, k, \result);
    assigns \nothing;
*/
int func2(int n, int k)
{
    int ans;

    //@ assert valid_range(n, k);
    //@ assert n <= k || n > k;
    //@ assert n <= 10 && k <= 10;

    ans = (n > k) ? 0 : (k - n);

    //@ assert postcondition(n, k, ans);
    return ans;
}

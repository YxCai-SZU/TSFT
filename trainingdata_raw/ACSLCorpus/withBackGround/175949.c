#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer func_res(integer n, integer a, integer b) =
        a * n < b ? a * n : b;

    lemma product_bound: \forall integer n, integer a, integer b;
        valid_params(n, a, b) ==> a * n <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int ans;
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    //@ assert a * n <= 1000;
    
    if (a * n < b) {
        ans = a * n;
    } else {
        ans = b;
    }
    
    return ans;
}

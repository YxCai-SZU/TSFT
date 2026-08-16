#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer n, integer x, int *l) =
        1 <= n <= 100 &&
        1 <= x <= 10000 &&
        \valid(l + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= l[i] <= 100;
*/

/*@
    requires valid_params(n, x, l);
    ensures 0 <= \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int ans = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= d <= i * 100;
        loop invariant 0 <= ans <= i;
        loop invariant d <= x + 100;
        loop assigns i, d, ans;
        loop variant n - i;
    */
    while (i < n) {
        int li = l[i];
        d += li;
        
        if (d <= x) {
            ans += 1;
        } else {
            break;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= ans <= n + 1;
    return ans;
}

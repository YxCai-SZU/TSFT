#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer n, integer m, int *days) =
        n >= 1 && n <= 1000000 &&
        m >= 1 && m <= 10000 &&
        \valid(days + (0 .. m-1)) &&
        \forall integer i; 0 <= i < m ==> days[i] >= 1 && days[i] <= 7;

    predicate ans_invariant(integer ans, integer n, integer i, integer m) =
        ans >= 0 && ans <= n && ans >= n - (i * 7);
*/

/*@
    lemma ans_bounds: \forall integer ans, n, i, m;
        ans_invariant(ans, n, i, m) ==> (ans >= 0 || ans == -1) && (ans >= 0 ==> ans <= n);
*/

/*@
    requires valid_params(n, m, days);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
    assigns \nothing;
*/
int func(int n, int m, int *days) {
    int ans = n;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= (size_t)m;
        loop invariant ans_invariant(ans, n, (int)i, m);
        loop invariant \forall integer j; 0 <= j < i ==> days[j] >= 1 && days[j] <= 7;
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < (size_t)m) {
        int day = days[i];
        //@ assert day >= 1 && day <= 7;
        
        ans -= day;
        
        if (ans < 0) {
            ans = -1;
            break;
        }
        
        //@ assert ans >= 0;
        i++;
    }
    
    //@ assert ans >= 0 || ans == -1;
    //@ assert ans >= 0 ==> ans <= n;
    return ans;
}

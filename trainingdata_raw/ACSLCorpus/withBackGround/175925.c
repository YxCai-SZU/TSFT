#include <stdbool.h>
#include <limits.h>

/*@ predicate is_valid_n(integer n) = 1 <= n <= 200000; */

/*@ predicate is_valid_p(integer n, int *p) =
    \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n &&
    \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]; */

/*@ predicate loop_invariant(integer n, int *p, integer i, integer ans, integer min_bound) =
    0 <= i <= n &&
    0 <= ans <= i &&
    1 <= min_bound <= INT_MAX &&
    \forall integer k; 0 <= k < i ==> 1 <= p[k] <= n &&
    \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j] &&
    is_valid_n(n) &&
    is_valid_p(n, p); */

/*@ lemma ans_bounds: \forall integer n, ans; 0 <= ans <= n ==> 0 <= ans <= n; */

/*@ requires is_valid_n(n);
    requires \valid(p+(0..n-1));
    requires is_valid_p(n, p);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int ans = 0;
    int min_bound = INT_MAX;
    int i = 0;
    
    /*@ loop invariant loop_invariant(n, p, i, ans, min_bound);
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        int num = p[i];
        if (num <= min_bound) {
            //@ assert num <= min_bound;
            ans += 1;
            min_bound = num;
        }
        i += 1;
    }
    //@ assert 0 <= ans <= n;
    return ans;
}

#include <stdbool.h>
/*@
    predicate valid_params(integer n, integer k, int *h) =
        1 <= n <= 100000 &&
        1 <= k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;

    predicate loop_invariant(integer n, integer k, int *h, integer index, integer ans) =
        0 <= index <= n &&
        0 <= ans <= index &&
        (index > 0 ==> \forall integer i; 0 <= i < index ==> (h[i] >= k ==> ans > 0)) &&
        valid_params(n, k, h) &&
        (\exists integer i; 0 <= i < index && h[i] >= k ==> ans > 0);

    lemma ans_bounds: \forall integer n, integer k, int *h, integer ans;
        loop_invariant(n, k, h, n, ans) ==> 0 <= ans <= n;

    lemma final_property: \forall integer n, integer k, int *h, integer ans;
        loop_invariant(n, k, h, n, ans) ==>
        \forall integer i; 0 <= i < n ==> (h[i] >= k ==> ans > 0);
*/

/*@
    requires valid_params(n, k, h);
    ensures 0 <= \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
    assigns \nothing;
*/
int func(int n, int k, int *h) {
    int ans = 0;
    int index = 0;
    /*@
        loop invariant loop_invariant(n, k, h, index, ans);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert loop_invariant(n, k, h, index, ans);
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
        //@ assert loop_invariant(n, k, h, index, ans);
    }
    //@ assert loop_invariant(n, k, h, n, ans);
    //@ assert \forall integer i; 0 <= i < n ==> (h[i] >= k ==> ans > 0);
    return ans;
}

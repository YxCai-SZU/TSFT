#include <stddef.h>

/*@
    predicate valid_array(integer n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        (\forall integer i; 0 <= i < n ==> 1 <= p[i] <= n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    predicate loop_invariant(integer n, integer i, integer ans, integer min_bound, int *p) =
        1 <= i <= n &&
        1 <= ans <= i &&
        min_bound <= p[0] &&
        (\forall integer k; 0 <= k < i ==> 1 <= p[k] <= n) &&
        (\forall integer k, j; 0 <= k < j < i ==> p[k] != p[j]);

    lemma array_properties_preserved:
        \forall integer n, i, int *p;
        valid_array(n, p) && 0 <= i < n ==>
            (\forall integer k; 0 <= k < n ==> 1 <= p[k] <= n) &&
            (\forall integer k, j; 0 <= k < j < n ==> p[k] != p[j]);
*/

/*@
    requires valid_array(n, p);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, const int *p) {
    int ans = 1;
    int min_bound = p[0];
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant 1 <= ans <= i;
        loop invariant min_bound <= p[0];
        loop invariant \forall integer k; 0 <= k < i ==> 1 <= p[k] <= n;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop invariant valid_array(n, p);
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        int j = p[i];
        
        //@ assert 1 <= j <= n;
        //@ assert \forall integer k; 0 <= k < i ==> p[k] != j;
        
        if (j <= min_bound) {
            //@ assert j <= min_bound;
            ans += 1;
            min_bound = j;
            //@ assert 1 <= ans <= i+1;
        }
        i += 1;
    }
    
    //@ assert 1 <= ans <= n;
    return ans;
}

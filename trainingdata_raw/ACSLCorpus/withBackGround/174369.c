#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(size_t n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0..n-1)) &&
        (\forall integer i; 0 <= i < n ==> 1 <= p[i] <= (int)n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    predicate loop_invariant(size_t n, int *p, size_t i, int ans, int min_bound) =
        1 <= i <= n &&
        1 <= ans <= (int)i &&
        min_bound <= p[0] &&
        valid_array(n, p);
*/

/*@
    requires valid_array(n, p);
    ensures 1 <= \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *p) {
    int ans = 1;
    int min_bound = p[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant 1 <= ans <= (int)i;
        loop invariant min_bound <= p[0];
        loop invariant valid_array(n, p);
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert valid_array(n, p);
        if (p[i] <= min_bound) {
            min_bound = p[i];
            ans += 1;
        }
        //@ assert 1 <= ans <= (int)(i+1);
        i += 1;
    }
    //@ assert 1 <= ans <= (int)n;
    return ans;
}

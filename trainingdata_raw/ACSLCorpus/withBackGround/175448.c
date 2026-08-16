#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *p, integer n) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    lemma cnt_non_negative:
        \forall integer cnt, i; cnt >= 0 && i >= 0 && cnt <= i ==> cnt >= 0;

    lemma idx_bounds:
        \forall integer idx, i, n; idx >= 1 && idx <= i+1 && i <= n ==> idx <= n+1;
*/

/*@
    requires valid_array(p, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *p) {
    int cnt = 0;
    int idx = 1;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= cnt <= i;
        loop invariant 1 <= idx <= i+1;
        loop invariant idx <= n+1;
        loop invariant valid_array(p, n);
        loop assigns cnt, idx, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (p[i] <= idx) {
            cnt += 1;
            idx += 1;
        }
        i += 1;
    }
    return cnt;
}

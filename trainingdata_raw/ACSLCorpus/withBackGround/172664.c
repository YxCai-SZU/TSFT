#include <stdbool.h>

/*@
    predicate valid_lengths(integer n, int *lengths) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> lengths[i] >= 1 && lengths[i] <= 100;

    predicate loop_invariant(integer n, integer x, integer i, integer ans, integer d, int *lengths) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        0 <= i && i <= n &&
        1 <= ans && ans <= i + 1 &&
        d >= 0 && d <= i * 100 &&
        \valid(lengths + (0..n-1)) &&
        valid_lengths(n, lengths) &&
        \forall integer k; 0 <= k < i ==> d >= lengths[k];

    lemma ans_bounds: \forall integer n, ans; 1 <= n && n <= 100 && 1 <= ans && ans <= n + 1 ==> ans >= 1 && ans <= n + 1;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= x && x <= 10000;
    requires \valid(lengths + (0..n-1));
    requires valid_lengths(n, lengths);
    ensures \result >= 1;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *lengths) {
    int ans;
    int d;
    int i;
    int l;

    ans = 1;
    d = 0;
    i = 0;

    /*@
        loop invariant loop_invariant(n, x, i, ans, d, lengths);
        loop assigns i, d, ans, l;
        loop variant n - i;
    */
    while (i < n) {
        l = lengths[i];
        d = d + l;

        //@ assert d >= 0 && d <= (i + 1) * 100;

        if (d > x) {
            break;
        }

        ans = ans + 1;
        i = i + 1;
    }

    //@ assert ans >= 1 && ans <= n + 1;
    return ans;
}

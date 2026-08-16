#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer x, int *ls) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        \valid(ls + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= ls[i] && ls[i] <= 100;

    predicate loop_invariant(integer n, integer x, int *ls, integer i, integer ans, integer d) =
        0 <= i && i <= n &&
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        \valid(ls + (0 .. n-1)) &&
        ans >= 1 &&
        ans <= i + 1 &&
        d >= 0 &&
        d <= i * 100 &&
        \forall integer j; 0 <= j < i ==> d >= ls[j] &&
        \forall integer k; 0 <= k < n ==> 1 <= ls[k] && ls[k] <= 100;

    lemma d_bound: \forall integer i, integer d; 0 <= i && d >= 0 && d <= i * 100 ==> d >= 0;
*/

/*@
    requires valid_params(n, x, ls);
    ensures \result >= 1 && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *ls)
{
    int ans = 1;
    int d = 0;
    int i = 0;

    /*@
        loop invariant loop_invariant(n, x, ls, i, ans, d);
        loop assigns i, d, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        int l = ls[i];
        d += l;

        if (d <= x)
        {
            ans += 1;
        }

        i += 1;
    }

    return ans;
}

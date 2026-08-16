#include <limits.h>

/*@
    predicate lower_bound(integer a, integer b, integer c, integer d, integer res) =
        res >= (a < b ? a : b) + (c < d ? c : d);

    predicate upper_bound(integer a, integer b, integer c, integer d, integer res) =
        res <= (a < b ? a : b) + (c < d ? c : d) * 2;

    lemma ans_satisfies_bounds:
        \forall integer a, b, c, d, s, t, min_val, res, ans;
            1 <= a <= 5000 && 1 <= b <= 5000 &&
            1 <= c <= 5000 && 1 <= d <= 5000 &&
            s == a + c && t == b + d &&
            min_val == (s < t ? s : t) &&
            res == (a < b ? a : b) + (c < d ? c : d) &&
            ans == (min_val < res ? min_val : res) ==>
            lower_bound(a, b, c, d, ans) && upper_bound(a, b, c, d, ans);
*/

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >= (a < b ? a : b) + (c < d ? c : d);
    ensures \result <= (a < b ? a : b) + (c < d ? c : d) * 2;
*/
int func(int a, int b, int c, int d)
{
    int res;
    int s;
    int t;
    int min_val;
    int ans;

    res = (a < b ? a : b) + (c < d ? c : d);
    s = a + c;
    t = b + d;
    min_val = s < t ? s : t;
    ans = min_val < res ? min_val : res;

    //@ assert lower_bound(a, b, c, d, ans);
    //@ assert upper_bound(a, b, c, d, ans);

    return ans;
}

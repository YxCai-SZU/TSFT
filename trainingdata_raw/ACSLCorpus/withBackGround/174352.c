/*@
    predicate is_permutation_sum(integer a, integer b, integer c, integer d, integer res) =
        res == a + b + c + d ||
        res == a + b + d + c ||
        res == a + c + b + d ||
        res == a + c + d + b ||
        res == a + d + b + c ||
        res == a + d + c + b;
 */

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures is_permutation_sum(a, b, c, d, \result);
 */
int func(int a, int b, int c, int d)
{
    int ans;
    int tmp;

    ans = a + b;

    //@ assert ans == a + b;
    if (ans < c) {
        tmp = ans + c;
    } else {
        tmp = c + ans;
    }
    ans = tmp;

    //@ assert ans == a + b + c || ans == c + a + b;
    if (ans < d) {
        tmp = ans + d;
    } else {
        tmp = d + ans;
    }
    ans = tmp;

    //@ assert is_permutation_sum(a, b, c, d, ans);
    return ans;
}

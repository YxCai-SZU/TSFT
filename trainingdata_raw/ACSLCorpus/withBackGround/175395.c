/*@
    predicate is_max(integer a, integer b, integer c, integer res) =
        (res == a && a >= b && a >= c) ||
        (res == b && b >= a && b >= c) ||
        (res == c && c >= a && c >= b);
 */

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures is_max(a, b, c, \result);
 */
int func(int a, int b, int c)
{
    int ans;
    ans = c;
    if (a >= b && a >= c)
    {
        ans = a;
    }
    else if (b >= a && b >= c)
    {
        ans = b;
    }
    //@ assert is_max(a, b, c, ans);
    return ans;
}

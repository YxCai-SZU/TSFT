/*@
    predicate valid_range(integer x) = 1 <= x <= 1000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    logic integer expected_sum(integer a, integer b, integer c, integer d) =
        min(a, b) + min(c, d);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result >= expected_sum(a, b, c, d);
    ensures \result == expected_sum(a, b, c, d) || \result == expected_sum(a, b, c, d) + 1;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    ans = min_ab + min_cd;

    //@ assert min_ab == min(a, b);
    //@ assert min_cd == min(c, d);
    //@ assert ans == expected_sum(a, b, c, d);

    if (a < b && b < c && c < d)
    {
        //@ assert ans == expected_sum(a, b, c, d);
        return ans;
    }
    else
    {
        //@ assert ans == expected_sum(a, b, c, d) || ans == expected_sum(a, b, c, d) + 1;
        return ans;
    }
}

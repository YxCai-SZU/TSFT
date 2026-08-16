/*@
    predicate is_nonnegative(integer v) = v >= 0;
    predicate is_within_range(integer v) = 1 <= v && v <= 1000000000;
    predicate quotient_bounds(integer q, integer x, integer d) = 0 <= q && q <= x / d;
    predicate remainder_relation(integer r, integer x, integer q, integer d) = r == x - q * d;
    logic integer absolute(integer v) = v < 0 ? -v : v;

    lemma remainder_nonnegative:
        \forall integer x, q, d;
        is_within_range(x) && quotient_bounds(q, x, d) && d > 0 ==>
        x - q * d >= 0;
*/

/*@
    requires is_within_range(x);
    ensures is_nonnegative(\result);
    ensures \result <= x;
*/
int func(int x)
{
    int q = 0;
    int abs_x;
    int divisor = 11;
    int r;
    int ans;

    if (x < 0)
    {
        abs_x = -x;
    }
    else
    {
        abs_x = x;
    }

    /*@
        loop invariant is_within_range(x);
        loop invariant quotient_bounds(q, x, divisor);
        loop invariant remainder_relation(abs_x, x, q, divisor);
        loop invariant is_nonnegative(abs_x);
        loop assigns q, abs_x;
    */
    while (abs_x >= divisor)
    {
        //@ assert abs_x >= divisor;
        abs_x -= divisor;
        q += 1;
    }

    r = abs_x;

    ans = 2 * q;
    if (r != 0)
    {
        ans += 1;
    }
    if (x < 0)
    {
        ans = -ans + 1;
    }

    //@ assert is_nonnegative(ans);
    //@ assert ans <= x;
    return ans;
}

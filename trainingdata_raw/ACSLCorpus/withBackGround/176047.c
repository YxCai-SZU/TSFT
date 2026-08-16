/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x <= 100000 &&
        1 <= y <= 100000 &&
        1 <= z <= 100000 &&
        y + 2 * z <= x;

    logic integer compute_ans(integer x, integer y, integer z) =
        (x - z) / (y + z);

    lemma ans_bounds:
        \forall integer x, y, z;
        valid_params(x, y, z) ==>
        0 <= compute_ans(x, y, z) <= x;
*/

/*@
    requires valid_params(x, y, z);
    ensures \result >= 0 && \result <= x;
    ensures \result == compute_ans(x, y, z);
    assigns \nothing;
*/
long func(long x, long y, long z)
{
    long ans;
    long numerator;
    long denominator;

    ans = 0;
    numerator = x - z;
    denominator = y + z;

    /*@
        loop invariant 0 <= numerator <= x - z;
        loop invariant ans >= 0;
        loop invariant ans * denominator == (x - z) - numerator;
        loop invariant ans <= x;
        loop assigns numerator, ans;
        loop variant numerator;
    */
    while (numerator >= denominator)
    {
        //@ assert numerator >= denominator;
        numerator -= denominator;
        ans += 1;
    }

    //@ assert ans == compute_ans(x, y, z);
    return ans;
}

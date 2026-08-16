/*@
    predicate l_in_range(integer l) = 1 <= l && l <= 1000;
    predicate temp_nonneg(integer temp) = temp >= 0;
    predicate ans_nonneg(integer ans) = ans >= 0;
    predicate division_invariant(integer l, integer temp, integer ans, integer divisor) =
        l * l * l == temp + ans * divisor;
*/

/*@
    logic integer cube(integer l) = l * l * l;
*/

/*@
    lemma cube_bound: \forall integer l; l_in_range(l) ==> cube(l) <= 1000000000;
    lemma square_bound: \forall integer l; l_in_range(l) ==> l * l <= 1000000;
*/

/*@
    requires 1 <= l <= 1000;
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
long func(int l)
{
    long ll = (long)l;
    long ans = 0;
    long temp = ll * ll * ll;
    long divisor = 27;

    //@ assert l_in_range(ll);
    //@ assert square_bound: ll * ll <= 1000000;
    //@ assert cube_bound: ll * ll * ll <= 1000000000;

    /*@
        loop invariant l_in_range(ll);
        loop invariant temp_nonneg(temp);
        loop invariant ans_nonneg(ans);
        loop invariant division_invariant(ll, temp, ans, divisor);
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        ans += 1;
    }

    return ans;
}

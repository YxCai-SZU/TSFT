/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    lemma product_bound:
        \forall integer t, s;
        1 <= t && t <= 10000 && 1 <= s && s <= 10000 ==>
        t * s <= 10000 * 10000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
int func(long long d, long long t, long long s)
{
    // Variable declarations at top of scope
    int result;

    //@ assert t > 0 && s > 0;
    //@ assert t <= 10000 && s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    result = (d <= t * s);
    return result;
}

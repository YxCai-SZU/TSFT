/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma product_bound:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/


int func(long long d, long long t, long long s)
{
    // Variable declarations at scope top
    int result;

    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert t * s <= 10000 * 10000;

    result = (d <= t * s);
    return result;
}

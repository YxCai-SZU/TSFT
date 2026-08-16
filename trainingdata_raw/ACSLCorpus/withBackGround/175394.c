/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma product_bound: \forall integer t, s;
        valid_range(t) && valid_range(s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
int func(int d, int t, int s)
{
    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert t * s <= 10000 * 10000;
    
    return d <= t * s;
}

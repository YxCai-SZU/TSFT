/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma product_bound:
        \forall integer s, t;
            valid_range(s) && valid_range(t) ==> s * t <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (s * t >= d);
*/
int func(int d, int t, int s)
{
    int d_fixed;
    int t_fixed;
    int s_fixed;
    int v;
    int result;

    d_fixed = d;
    t_fixed = t;
    s_fixed = s;

    //@ assert valid_range(s_fixed);
    //@ assert valid_range(t_fixed);
    //@ assert s_fixed * t_fixed <= 10000 * 10000;

    v = s_fixed * t_fixed;

    //@ assert v == s * t;
    //@ assert v <= 10000 * 10000;

    result = (v >= d_fixed);
    return result;
}

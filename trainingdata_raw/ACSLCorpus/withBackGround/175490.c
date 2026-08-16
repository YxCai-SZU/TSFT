/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int min_val;
    int max_val;
    int res;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    sa = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    sc = c * d;

    if (sa < sc)
    {
        min_val = sa;
    }
    else
    {
        min_val = sc;
    }

    if (sa > sc)
    {
        max_val = sa;
    }
    else
    {
        max_val = sc;
    }

    if (min_val < max_val)
    {
        res = max_val;
    }
    else
    {
        res = min_val;
    }

    //@ assert res == product(a, b) || res == product(c, d);
    //@ assert res >= product(a, b);
    //@ assert res >= product(c, d);
    return res;
}

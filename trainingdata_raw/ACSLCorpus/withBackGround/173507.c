/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        1 <= product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b) && \result >= product(c, d);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int sa;
    unsigned int sc;
    unsigned int res;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    sa = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    sc = c * d;

    //@ assert 1 <= product(a, b) <= 100000000;
    //@ assert 1 <= product(c, d) <= 100000000;

    //@ assert product(a, b) >= 1;
    //@ assert product(c, d) >= 1;

    if (sa > sc)
    {
        res = sa;
        //@ assert res == product(a, b);
    }
    else
    {
        res = sc;
        //@ assert res == product(c, d);
    }

    //@ assert res >= product(a, b) && res >= product(c, d);
    return res;
}

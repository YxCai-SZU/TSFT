/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            1 <= product(a, b) <= 100000000;

    lemma product_reflexive:
        \forall integer a, b, x;
            valid_range(a) && valid_range(b) && x == product(a, b) ==>
            x >= product(a, b) && x <= product(a, b);
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
    int x;
    int y;
    int result;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    x = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    y = c * d;

    //@ assert x == product(a, b);
    //@ assert x >= product(a, b) && x <= product(a, b);
    //@ assert x >= 1 && x <= 100000000;

    //@ assert y == product(c, d);
    //@ assert y >= product(c, d) && y <= product(c, d);
    //@ assert y >= 1 && y <= 100000000;

    if (x > y)
    {
        //@ assert x >= product(a, b);
        //@ assert x >= product(c, d);
        result = x;
    }
    else
    {
        //@ assert y >= product(a, b);
        //@ assert y >= product(c, d);
        result = y;
    }

    return result;
}

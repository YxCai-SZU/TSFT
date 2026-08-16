/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 100000000;

    lemma product_positive:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) >= 1;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int product_ab;
    int product_cd;
    int result;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    product_ab = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    product_cd = c * d;

    if (product_ab > product_cd) {
        result = product_ab;
    } else {
        result = product_cd;
    }

    //@ assert result == product(a, b) || result == product(c, d);
    //@ assert result >= 1;

    return result;
}

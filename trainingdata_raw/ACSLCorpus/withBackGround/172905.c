/*@
    predicate bounds(integer v) = 1 <= v && v <= 20;

    lemma product_bounds:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> 0 <= x * y && x * y <= 400;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result >= 0;
    ensures \result == b * c || \result == a * d || \result == c * d || \result == a * b;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Declare all variables at the top
    int res;

    //@ assert bounds(b);
    //@ assert bounds(c);
    //@ assert b * c >= 0;
    //@ assert b * c <= 400;

    res = b * c;

    //@ assert bounds(a);
    //@ assert bounds(d);
    //@ assert a * d >= 0;
    //@ assert a * d <= 400;

    if (res < a * d) {
        res = a * d;
    }

    //@ assert bounds(c);
    //@ assert bounds(d);
    //@ assert c * d >= 0;
    //@ assert c * d <= 400;

    if (res < c * d) {
        res = c * d;
    }

    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert a * b >= 0;
    //@ assert a * b <= 400;

    if (res < a * b) {
        res = a * b;
    }

    //@ assert res >= 0;
    //@ assert res == b * c || res == a * d || res == c * d || res == a * b;

    return res;
}

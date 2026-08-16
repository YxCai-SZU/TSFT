/*@
    predicate bounds(integer v) = -1000000000 <= v <= 1000000000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds_low:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> product(x, y) >= -1000000000000000000;

    lemma product_bounds_high:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> product(x, y) <= 1000000000000000000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    requires a <= b && c <= d;
    ensures \result == product(b, d) ||
            \result == product(b, c) ||
            \result == product(a, d) ||
            \result == product(a, c);
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long res;

    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    //@ assert bounds(d);

    //@ assert product(a, c) >= -1000000000000000000;
    //@ assert product(a, c) <= 1000000000000000000;
    //@ assert product(a, d) >= -1000000000000000000;
    //@ assert product(a, d) <= 1000000000000000000;
    //@ assert product(b, c) >= -1000000000000000000;
    //@ assert product(b, c) <= 1000000000000000000;
    //@ assert product(b, d) >= -1000000000000000000;
    //@ assert product(b, d) <= 1000000000000000000;

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }

    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }

    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }

    return res;
}

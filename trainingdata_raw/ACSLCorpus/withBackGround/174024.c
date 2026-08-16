/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        -10000 <= a <= 10000 &&
        -10000 <= b <= 10000 &&
        -10000 <= c <= 10000 &&
        -10000 <= d <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer a, c;
        bounds(a, 0, c, 0) ==> -1000000000 <= product(a, c) <= 1000000000;

    lemma max1_property:
        \forall integer a, c, d, max1;
        bounds(a, 0, c, d) &&
        (max1 == product(a, c) || max1 == product(a, d)) &&
        max1 >= product(a, c) && max1 >= product(a, d) ==>
        max1 >= product(a, c) && max1 >= product(a, d);

    lemma max2_property:
        \forall integer b, c, d, max2;
        bounds(0, b, c, d) &&
        (max2 == product(b, c) || max2 == product(b, d)) &&
        max2 >= product(b, c) && max2 >= product(b, d) ==>
        max2 >= product(b, c) && max2 >= product(b, d);
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == product(a, c) ||
            \result == product(a, d) ||
            \result == product(b, c) ||
            \result == product(b, d);
    ensures \result >= product(a, c);
    ensures \result >= product(a, d);
    ensures \result >= product(b, c);
    ensures \result >= product(b, d);
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long res;

    //@ assert bounds(a, b, c, d);

    //@ assert -1000000000 <= a * c <= 1000000000;
    //@ assert -1000000000 <= a * d <= 1000000000;
    //@ assert -1000000000 <= b * c <= 1000000000;
    //@ assert -1000000000 <= b * d <= 1000000000;

    if (a * c > a * d)
        max1 = a * c;
    else
        max1 = a * d;

    //@ assert max1 == a * c || max1 == a * d;
    //@ assert max1 >= a * c && max1 >= a * d;

    if (b * c > b * d)
        max2 = b * c;
    else
        max2 = b * d;

    //@ assert max2 == b * c || max2 == b * d;
    //@ assert max2 >= b * c && max2 >= b * d;

    if (max1 > max2)
        res = max1;
    else
        res = max2;

    //@ assert res == a * c || res == a * d || res == b * c || res == b * d;
    //@ assert res >= a * c && res >= a * d && res >= b * c && res >= b * d;

    return res;
}

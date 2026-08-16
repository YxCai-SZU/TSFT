/*@
    predicate is_within_bounds(integer x, integer y) =
        1 <= x <= 10000 && 1 <= y <= 10000;

    lemma assert_within_bounds:
        \forall integer x, y;
            is_within_bounds(x, y) ==> x * y <= 10000 * 10000;
*/

/*@
    requires is_within_bounds(a, b);
    requires is_within_bounds(c, d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
*/
long func(long a, long b, long c, long d) {
    long sa;
    long sc;
    long res;

    //@ assert is_within_bounds(a, b);
    //@ assert is_within_bounds(c, d);
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    sa = a * b;
    sc = c * d;

    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }

    //@ assert res == a * b || res == c * d;
    //@ assert res >= a * b;
    //@ assert res >= c * d;

    return res;
}

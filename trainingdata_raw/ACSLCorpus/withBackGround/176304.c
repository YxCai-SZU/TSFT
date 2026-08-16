/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    lemma sum_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> a + b <= 200;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long res;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    if (a < b) {
        x = a;
    } else {
        x = b;
    }

    //@ assert x == a || x == b;
    //@ assert in_range(x);

    if (c < d) {
        y = c;
    } else {
        y = d;
    }

    //@ assert y == c || y == d;
    //@ assert in_range(y);

    //@ assert x + y <= 200;
    //@ assert x + y == a + c || x + y == a + d || x + y == b + c || x + y == b + d;

    res = x + y;
    return res;
}

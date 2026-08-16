/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    lemma product_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int res;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;

    //@ assert s1 == a * b || s2 == c * d;

    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }

    //@ assert res == a * b || res == c * d;
    //@ assert res >= a * b && res >= c * d;

    return res;
}

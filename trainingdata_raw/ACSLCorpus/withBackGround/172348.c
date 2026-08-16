/*@
    predicate exactly_one_pair_equal(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && b != a);
 */

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> exactly_one_pair_equal(a, b, c);
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int s = 0;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b)
    {
        s += 1;
    }

    if (a == c)
    {
        s += 1;
    }

    if (b == c)
    {
        s += 1;
    }

    //@ assert s == 1 ==> exactly_one_pair_equal(a, b, c);

    return s == 1;
}

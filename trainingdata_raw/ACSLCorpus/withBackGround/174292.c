/*@
    predicate two_equal_one_different(integer a, integer b, integer c) =
        (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
 */

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> two_equal_one_different(a, b, c);
 */
int func(long long a, long long b, long long c)
{
    int tmp = 0;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b)
    {
        tmp += 1;
    }

    //@ assert tmp == (a == b ? 1 : 0);

    if (a == c)
    {
        tmp += 1;
    }

    //@ assert tmp == (a == b ? 1 : 0) + (a == c ? 1 : 0);

    if (b == c)
    {
        tmp += 1;
    }

    //@ assert tmp == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);
    //@ assert tmp == 1 <==> two_equal_one_different(a, b, c);

    return tmp == 1;
}

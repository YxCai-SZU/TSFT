/*@
    predicate exactly_two_equal(integer a, integer b, integer c) =
        (a == b && c != a && c != b) ||
        (a == c && b != a && b != c) ||
        (b == c && a != b && a != c);
 */

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> exactly_two_equal(a, b, c);
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int answer = 0;

    if (a == b)
    {
        if (c != a && c != b)
        {
            answer = 1;
        }
    }
    else if (a == c)
    {
        if (b != a && b != c)
        {
            answer = 1;
        }
    }
    else if (b == c)
    {
        if (a != b && a != c)
        {
            answer = 1;
        }
    }

    //@ assert answer == 1 <==> exactly_two_equal(a, b, c);
    return answer;
}

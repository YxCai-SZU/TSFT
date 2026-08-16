/*@
    predicate is_distinct(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    predicate is_mid(integer a, integer b, integer c) =
        (a < c && c < b) || (b < c && c < a);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires is_distinct(a, b, c);
    ensures \result == 1 <==> is_mid(a, b, c);
*/
int func(int a, int b, int c)
{
    int max;
    int min;
    int result;

    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }

    min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }

    //@ assert max == a || max == b || max == c;
    //@ assert min == a || min == b || min == c;
    //@ assert max != min;

    result = (max != c) && (min != c);
    return result;
}

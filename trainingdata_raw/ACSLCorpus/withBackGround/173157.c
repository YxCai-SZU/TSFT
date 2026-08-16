/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer func_spec(integer a, integer b, integer c) =
        (a == b && a != c) ? c :
        (a == c && a != b) ? b :
        (b == c && a != b) ? a :
        a;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == func_spec(a, b, c);
    ensures in_range(\result);
*/
int func(int a, int b, int c)
{
    int result = a;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(result);

    if (a == b)
    {
        result = c;
        //@ assert in_range(result);
    }

    if (b == c)
    {
        result = a;
        //@ assert in_range(result);
    }

    if (c == a)
    {
        result = b;
        //@ assert in_range(result);
    }

    //@ assert in_range(result);
    return result;
}

/*@
    predicate is_between(integer a, integer b, integer c) =
        (c > a && c < b) || (c > b && c < a);
*/

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == 1 <==> is_between(a, b, c);
*/
int func(int a, int b, int c)
{
    int x;
    int y;
    int result;

    if (a < b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    //@ assert x <= y;
    result = (c > x && c < y) ? 1 : 0;
    return result;
}

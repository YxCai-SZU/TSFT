/*@
    predicate is_sum(integer a, integer b, integer c) =
        (a + b == c) || (b + c == a) || (c + a == b);
 */

/*@
    requires a <= 100;
    requires b <= 100;
    requires c <= 100;
    ensures \result == 1 <==> is_sum(a, b, c);
    assigns \nothing;
 */
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result = 0;

    //@ assert a + b <= 200;

    if (a + b == c)
    {
        result = 1;
    }
    else if (b + c == a)
    {
        result = 1;
    }
    else if (c + a == b)
    {
        result = 1;
    }

    //@ assert result == 1 <==> is_sum(a, b, c);

    return result;
}

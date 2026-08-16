/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    predicate post_condition(integer result, integer a, integer b, integer c) =
        result >= 0 &&
        result <= c &&
        (result == c - (a - b) || result == 0);
*/

/*@
    requires valid_input(a, b, c);
    ensures post_condition(\result, a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert a - b >= 0;
    //@ assert a - b <= 20;
    //@ assert c >= 0;
    //@ assert c <= 20;

    if (c > (a - b))
    {
        //@ assert c - (a - b) >= 0;
        result = c - (a - b);
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }

    return result;
}

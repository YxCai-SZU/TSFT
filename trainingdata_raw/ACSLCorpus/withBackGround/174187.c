/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires a >= -2147483648 && a <= 2147483647;
    requires b >= -2147483648 && b <= 2147483647;
    requires c >= -2147483648 && c <= 2147483647;
    ensures \result == 1 <==> is_ordered(a, b, c);
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert a >= -2147483648 && a <= 2147483647;
    
    if (a < b)
    {
        //@ assert b >= -2147483648 && b <= 2147483647;
        if (b < c)
        {
            //@ assert is_ordered(a, b, c);
            result = 1;
        }
        else
        {
            //@ assert !is_ordered(a, b, c);
            result = 0;
        }
    }
    else
    {
        //@ assert !is_ordered(a, b, c);
        result = 0;
    }
    
    //@ assert result == 1 <==> is_ordered(a, b, c);
    return result;
}

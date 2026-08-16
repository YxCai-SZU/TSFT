/*@
    predicate is_ordered(integer a, integer b, integer c) = a < b && b < c;
*/

/*@
    lemma func_lemma:
        \forall integer a, b, c;
            a >= -2147483648 && a <= 2147483647 &&
            b >= -2147483648 && b <= 2147483647 &&
            c >= -2147483648 && c <= 2147483647 ==>
            (a < b && b < c ==> is_ordered(a, b, c)) &&
            (!(a < b && b < c) ==> !is_ordered(a, b, c));
*/

/*@
    requires a >= -2147483648 && a <= 2147483647;
    requires b >= -2147483648 && b <= 2147483647;
    requires c >= -2147483648 && c <= 2147483647;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert a >= -2147483648 && a <= 2147483647;
    //@ assert b >= -2147483648 && b <= 2147483647;
    //@ assert c >= -2147483648 && c <= 2147483647;
    
    if (a < b)
    {
        if (b < c)
        {
            result = 1;
            //@ assert is_ordered(a, b, c);
        }
        else
        {
            result = 0;
            //@ assert !is_ordered(a, b, c);
        }
    }
    else
    {
        result = 0;
        //@ assert !is_ordered(a, b, c);
    }
    
    //@ assert result == (a < b && b < c);
    return result;
}

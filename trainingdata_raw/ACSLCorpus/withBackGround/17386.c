/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    lemma result_bounds:
        \forall integer a, b, c, r;
        valid_range(a, b, c) && r == c - a + b ==>
        (r > 0 ==> r <= a - b + c) &&
        (r <= 0 ==> 0 <= a - b + c);
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert valid_range(a, b, c);
    
    result = c - a + b;
    
    if (result > 0)
    {
        //@ assert result == c - a + b;
        //@ assert result <= a - b + c;
        return result;
    }
    else
    {
        //@ assert 0 <= a - b + c;
        return 0;
    }
}

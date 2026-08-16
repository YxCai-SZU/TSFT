/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int q;
    int res;

    q = a - b;
    
    if (c > q)
    {
        res = q;
    }
    else
    {
        res = c;
    }
    
    //@ assert (c > q) ==> (res == q);
    //@ assert !(c > q) ==> (res == c);
    
    if (res < 0)
    {
        res = -res;
    }
    
    return res;
}

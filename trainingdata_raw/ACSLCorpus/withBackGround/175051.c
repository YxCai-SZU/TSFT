/*@
    predicate is_between(integer a, integer b, integer c) =
        (a <= c && c <= b) || (a >= c && c >= b);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b;
    requires b != c;
    requires a != c;
    ensures \result == 1 <==> is_between(a, b, c);
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= c <= 100;
    //@ assert a != b;
    //@ assert b != c;
    //@ assert a != c;
    
    if ((a <= c && c <= b) || (a >= c && c >= b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

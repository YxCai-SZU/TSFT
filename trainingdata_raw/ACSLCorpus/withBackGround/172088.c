/*@
    predicate two_equal_one_different(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (b == c && b != a) ||
        (a == c && a != b);
 */

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == 1 <==> two_equal_one_different(a, b, c);
 */
int func(int a, int b, int c)
{
    int result;
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if ((a == b && b != c) ||
        (b == c && b != a) ||
        (c == a && c != b))
    {
        result = 1;
        //@ assert two_equal_one_different(a, b, c);
    }
    else
    {
        result = 0;
        //@ assert !two_equal_one_different(a, b, c);
    }
    
    return result;
}

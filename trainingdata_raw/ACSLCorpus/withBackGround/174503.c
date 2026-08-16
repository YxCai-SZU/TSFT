/*@
    predicate condition(integer a, integer b, integer c, integer d) =
        a <= b && c <= d && a <= c && b >= d;
 */

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    requires 1 <= d && d <= 10000;
    ensures \result == 1 <==> condition(a, b, c, d);
 */
int func(int a, int b, int c, int d)
{
    int result;
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    
    if (a <= b && c <= d && a <= c && b >= d) {
        //@ assert condition(a, b, c, d);
        result = 1;
    } else {
        //@ assert !condition(a, b, c, d);
        result = 0;
    }
    
    return result;
}

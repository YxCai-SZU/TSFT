/*@
    predicate in_range(integer x) = 1 <= x && x <= 10000;
    predicate product_in_range(integer x, integer y) = 
        in_range(x) && in_range(y) ==> 
        x * y >= 1 && x * y <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1 && \result <= 100000000;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int res;

    //@ assert product_in_range(a, b);
    //@ assert product_in_range(c, d);
    
    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    return res;
}

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate within_bounds(integer x) = 0 <= x && x <= 10000;
    predicate product_in_range(integer x, integer y) = 
        0 <= x * y && x * y <= 10000 * 10000;
*/

/*@
    logic integer max_product(integer a, integer b, integer c, integer d) =
        (a * b >= c * d) ? a * b : c * d;
*/

/*@
    lemma product_nonnegative:
        \forall integer a, b, c, d;
            within_bounds(a) && within_bounds(b) && 
            within_bounds(c) && within_bounds(d) ==>
            is_nonnegative(max_product(a, b, c, d));
*/

/*@
    lemma product_choice:
        \forall integer a, b, c, d;
            within_bounds(a) && within_bounds(b) && 
            within_bounds(c) && within_bounds(d) ==>
            max_product(a, b, c, d) == a * b || 
            max_product(a, b, c, d) == c * d;
*/

/*@
    requires 0 <= a && a <= 10000;
    requires 0 <= b && b <= 10000;
    requires 0 <= c && c <= 10000;
    requires 0 <= d && d <= 10000;
    ensures \result == a * b || \result == c * d;
    ensures \result >= 0;
*/
int func(int a, int b, int c, int d)
{
    int res;
    
    //@ assert 0 <= a * b && a * b <= 10000 * 10000;
    //@ assert 0 <= c * d && c * d <= 10000 * 10000;
    
    if (a * b >= c * d) {
        res = a * b;
    } else {
        res = c * d;
    }
    
    //@ assert res == a * b || res == c * d;
    //@ assert res >= 0;
    
    return res;
}

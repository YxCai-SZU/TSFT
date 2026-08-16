/*@
    predicate in_range(integer x) = -1000000000 <= x <= 1000000000;
    
    logic integer max_product(integer a, integer b, integer c, integer d) =
        \max(\max(a*c, b*c), \max(b*d, a*d));
    
    lemma product_in_range:
        \forall integer a, b, c, d;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) ==>
            -1000000000000000000 <= a*c <= 1000000000000000000 &&
            -1000000000000000000 <= b*c <= 1000000000000000000 &&
            -1000000000000000000 <= b*d <= 1000000000000000000 &&
            -1000000000000000000 <= a*d <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && a <= b;
    requires in_range(c) && in_range(d) && c <= d;
    ensures \result == a*d || \result == b*c || \result == b*d || \result == a*c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long f;
    long s;
    long result;
    
    //@ assert -1000000000000000000 <= a*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*d <= 1000000000000000000;
    //@ assert -1000000000000000000 <= a*d <= 1000000000000000000;
    
    if (a * c > b * c) {
        f = a * c;
    } else {
        f = b * c;
    }
    
    if (b * d > a * d) {
        s = b * d;
    } else {
        s = a * d;
    }
    
    if (f > s) {
        result = f;
    } else {
        result = s;
    }
    
    //@ assert result == a*d || result == b*c || result == b*d || result == a*c;
    return result;
}

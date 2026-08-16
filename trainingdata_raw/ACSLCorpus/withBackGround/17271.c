/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10000;
    predicate b_in_range(integer b) = 1 <= b && b <= 10000;
    predicate c_in_range(integer c) = 1 <= c && c <= 10000;
    predicate d_in_range(integer d) = 1 <= d && d <= 10000;
    
    lemma product_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long s;
    
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        s = sa;
    } else {
        s = sc;
    }
    
    //@ assert s >= a * b;
    //@ assert s >= c * d;
    
    return s;
}

int main()
{
    long a;
    long b;
    long c;
    long d;
    long result;
    
    a = 2;
    b = 3;
    c = 4;
    d = 5;
    
    result = func(a, b, c, d);
    
    //@ assert result == a * b || result == c * d;
    //@ assert result >= a * b;
    //@ assert result >= c * d;
    
    return 0;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            product(x, y) >= 1 && product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int res;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) >= 1 && product(a, b) <= 10000 * 10000;
    
    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) >= 1 && product(c, d) <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;
    
    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }
    
    //@ assert res == product(a, b) || res == product(c, d);
    //@ assert res >= 1;
    
    return res;
}

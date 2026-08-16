/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 10 &&
        1 <= b && b <= 10;
        
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_in_range:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) && product(a, b) <= 100;
*/

/*@
    requires valid_range(a, b);
    ensures \result == product(a, b);
    ensures 1 <= \result && \result <= 100;
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    
    //@ assert valid_range(a, b);
    //@ assert 1 <= product(a, b) && product(a, b) <= 100;
    
    res = a * b;
    
    //@ assert res == product(a, b);
    //@ assert 1 <= res && res <= 100;
    
    return res;
}

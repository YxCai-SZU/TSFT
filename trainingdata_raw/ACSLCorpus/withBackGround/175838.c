/*@
    predicate valid_range(integer x) = 1 <= x <= 20;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> multiply(a, b) <= 400;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int res;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert multiply(a, b) <= 400;
    
    res = a * b;
    
    //@ assert res == multiply(a, b);
    return res;
}

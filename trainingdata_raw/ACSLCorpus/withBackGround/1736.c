/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires 1 <= in_a <= 100;
    requires 1 <= in_b <= 100;
    ensures \result == in_a * in_b;
    assigns \nothing;
*/
int func(int in_a, int in_b)
{
    int c;
    
    //@ assert 1 <= in_a && in_a <= 100;
    //@ assert 1 <= in_b && in_b <= 100;
    //@ assert 1 <= in_a * in_b && in_a * in_b <= 10000;
    
    c = in_a * in_b;
    
    //@ assert c == in_a * in_b;
    return c;
}

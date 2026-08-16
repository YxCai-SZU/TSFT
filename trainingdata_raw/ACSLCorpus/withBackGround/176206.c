/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) && product(a, b) <= 10000;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == product(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert product(A, B) <= 10000;
    //@ assert product(A, B) >= 1;
    
    return A * B;
}

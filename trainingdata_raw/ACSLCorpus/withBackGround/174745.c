/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> product(a, b) <= 10000;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == product(A, B);
    assigns \nothing;
*/
unsigned long func(unsigned long A, unsigned long B) {
    unsigned long ans;
    
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert product(A, B) <= 10000;
    
    ans = A * B;
    
    //@ assert ans == product(A, B);
    return ans;
}

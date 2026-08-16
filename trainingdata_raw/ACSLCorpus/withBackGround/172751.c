/*@
    predicate is_odd(integer x) = x % 2 != 0;
    predicate both_odd(integer a, integer b) = is_odd(a) && is_odd(b);
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_odd_iff: 
        \forall integer a, b; 
        is_odd(product(a, b)) <==> both_odd(a, b);
*/

/*@
    requires 1 <= A <= 10000;
    requires 1 <= B <= 10000;
    ensures \result == ((A * B) % 2 != 0);
    ensures \result <==> (A % 2 != 0 && B % 2 != 0);
*/
int func(unsigned int A, unsigned int B) {
    // Variable declarations at scope top
    unsigned int product;
    int result;
    
    //@ assert 1 <= A <= 10000;
    //@ assert 1 <= B <= 10000;
    
    // Prevent overflow verification
    //@ assert A * B <= 10000 * 10000;
    
    product = A * B;
    result = (product % 2 != 0);
    
    // Final verification property
    //@ assert result == ((A * B) % 2 != 0);
    
    return result;
}

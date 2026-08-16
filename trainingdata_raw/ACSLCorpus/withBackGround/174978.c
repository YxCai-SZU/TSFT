/*@
    predicate is_within_bounds(integer n) = 1 <= n && n <= 100;
    predicate loop_invariant(integer n, integer i) = 0 <= i && i <= n;
    
    lemma square_bound: \forall integer n; is_within_bounds(n) ==> n * n <= 100 * 100;
*/

/*@
    requires is_within_bounds(n);
    ensures \result == n * n;
    assigns \nothing;
*/
unsigned int func(unsigned int n) {
    // Variable declarations
    unsigned int i;
    
    // Precondition check
    //@ assert is_within_bounds(n);
    
    i = 0;
    
    /*@
        loop invariant loop_invariant(n, i);
        loop invariant is_within_bounds(n);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        i = i + 1;
    }
    
    // Postcondition verification
    //@ assert n * n <= 100 * 100;
    
    return n * n;
}

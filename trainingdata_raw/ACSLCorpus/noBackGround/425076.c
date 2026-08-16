/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
unsigned long func(unsigned long n, unsigned long a) {
    // Variable declarations at scope top
    unsigned long result;
    
    // Precondition verification
    //@ assert n * n >= a;
    //@ assert n <= 100;
    //@ assert a <= n * n;
    //@ assert n * n <= 10000;
    
    // Proof lemma application
    //@ assert n * n - a == n * n - a;
    
    result = n * n - a;
    return result;
}

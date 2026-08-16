/*@
    requires (1 <= (n) <= 100000 && 1 <= (k) <= (n));
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k) {
    // Variable declarations at scope top
    unsigned int res;
    
    //@ assert k <= n;
    //@ assert n - k + 1 >= 1;
    //@ assert n - k + 1 <= 100000;
    
    res = n - k + 1;
    return res;
}

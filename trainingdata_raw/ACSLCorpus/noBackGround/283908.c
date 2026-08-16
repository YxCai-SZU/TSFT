/*@
    requires (0 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= 100);
    ensures \result == ((n) * (m));
    assigns \nothing;
*/
unsigned long func(unsigned long n, unsigned long m) {
    unsigned long ans;
    
    //@ assert ((n) * (m)) <= 100 * 100;
    
    ans = n * m;
    
    //@ assert ans == ((n) * (m));
    
    return ans;
}

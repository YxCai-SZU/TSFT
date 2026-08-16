/*@
    requires (1 <= (k) && (k) <= 100);
    requires (1 <= (x) && (x) <= 100000);
    ensures ((\result) == ((x) <= 500 * (k)));
    assigns \nothing;
*/
int func(unsigned int k, unsigned int x) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100000);
    
    //@ assert (500 * (k)) <= 50000;
    
    result = (x <= 500 * k);
    
    //@ assert ((result) == ((x) <= 500 * (k)));
    return result;
}

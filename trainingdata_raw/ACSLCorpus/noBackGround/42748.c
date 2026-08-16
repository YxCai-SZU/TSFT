/*@
    requires a <= b;
    requires b <= c;
    requires c <= d;
    requires d <= e;
    ensures \result == (a <= e);
    assigns \nothing;
*/
_Bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    // Variable declarations at top of scope
    _Bool result;
    
    // Proof block translated to ACSL assertion
    //@ assert a <= e;
    
    result = a <= e;
    return result;
}

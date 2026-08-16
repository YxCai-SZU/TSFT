/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) < 6);
    ensures \result == ((a) + (((b)) * 2));
    ensures \result <= 112;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) < 6);
    
    //@ assert ((b) * 2) <= 10;
    //@ assert ((a) + (((b)) * 2)) <= 112;
    
    result = a + b * 2;
    
    //@ assert result == ((a) + (((b)) * 2));
    //@ assert result <= 112;
    
    return result;
}

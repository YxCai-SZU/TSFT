/*@
    requires ((a) > 0) && ((b) > 0);
    ensures \result == ((a & b) > 0);
*/
int func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    int result;
    
    //@ assert ((a) > 0);
    //@ assert ((b) > 0);
    
    result = (a & b) > 0;
    
    //@ assert result == ((a & b) > 0);
    
    return result;
}

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
*/
unsigned int func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);
    
    //@ assert a * b <= 100 * 100;
    //@ assert a * b >= a + b;
    
    result = a * b - a - b + 1;
    
    //@ assert result == ((a) * (b) - (a) - (b) + 1);
    //@ assert result > 0;
    
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a * b) % 2);
    assigns \nothing;
*/
int myfun(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    unsigned int product;
    int result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    //@ assert a * b <= 10000;
    
    product = a * b;
    result = (int)(product % 2);
    
    //@ assert result == ((a * b) % 2);
    return result;
}

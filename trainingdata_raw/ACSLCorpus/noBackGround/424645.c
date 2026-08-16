/*@
    requires a <= b;
    requires b < 0x100000000;
    ensures \result <==> (a <= b && ((b) % 2 == 0));
*/
int func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    int result;
    
    //@ assert a <= b && b < 0x100000000;
    result = (a <= b) && (b % 2 == 0);
    return result;
}

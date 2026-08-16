/*@
    requires ((b) != 0);
    ensures ((a) / (b) * (b) + (a) % (b) == (a));
*/
void func(int a, int b) {
    // Variable declarations at scope top
    int quotient;
    int remainder;
    int result;
    
    //@ assert b != 0;
    
    quotient = a / b;
    remainder = a % b;
    result = quotient * b + remainder;
    
    //@ assert result == a;
}

/*@
    requires ((a) >= -2147483648 && (a) <= 2147483647) && ((b) >= -2147483648 && (b) <= 2147483647);
    ensures \result == a || \result == b;
    ensures \result <= a && \result <= b;
*/
int minimum(int a, int b) {
    // Declare all variables at the top
    int ret;
    
    //@ assert ((a) >= -2147483648 && (a) <= 2147483647);
    //@ assert ((b) >= -2147483648 && (b) <= 2147483647);
    
    if (a < b) {
        ret = a;
    } else {
        ret = b;
    }
    
    return ret;
}

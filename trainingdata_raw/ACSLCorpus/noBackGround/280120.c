/*@
    requires a > 0 && b >= 0;
    ensures \result >= 0;
*/
int example_function(int a, int b) {
    int result;
    
    //@ assert a > 0 && b >= 0;
    result = a * b;
    //@ assert result >= 0;
    
    return result;
}

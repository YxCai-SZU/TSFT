/*@
    requires a <= b;
    ensures \result == 1 <==> a == b;
    assigns \nothing;
*/
int example_function(int a, int b) {
    int result;
    
    //@ assert a <= b;
    
    result = (a == b) ? 1 : 0;
    
    return result;
}

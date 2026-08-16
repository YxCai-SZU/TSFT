/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 10;
    ensures \result >= x;
*/
int nonlinear_arithmetic_impl(int x, int y) {
    int result;
    
    //@ assert ((y * y) >= 0);
    //@ assert (2 * (x)) >= x;
    
    result = 2 * x + y * y;
    
    //@ assert result >= x;
    return result;
}

int main() {
    return 0;
}

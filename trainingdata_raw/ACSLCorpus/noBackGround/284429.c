/*@
    requires (0 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) * (b));
*/
int func(int a, int b) {
    int sum;
    int product;
    int result;
    
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    
    sum = a + b;
    
    //@ assert 0 <= a * b && a * b <= 10000;
    product = a * b;
    
    if (sum > product) {
        result = sum;
    } else {
        result = product;
    }
    
    //@ assert result == sum || result == product;
    return result;
}

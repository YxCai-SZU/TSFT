/*@
    requires ((a) * (b) == 6);
    ensures \result == 0;
*/
int example_3(int a, int b) {
    //@ assert a * b == 6;
    
    int product = a * b;
    //@ assert product == 6;
    
    int triple = product + product + product;
    //@ assert triple == 18;
    
    //@ assert triple <= 18;
    return 0;
}

int main() {
    return 0;
}

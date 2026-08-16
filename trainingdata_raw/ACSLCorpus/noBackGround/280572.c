/*@
requires a == b && b == c;
ensures a == c;
*/
void proof_example_n(int a, int b, int c) {
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
}

int main() {
    int x;
    int y;
    
    x = 4;
    y = 4;
    
    //@ assert x == y;
    //@ assert 2 * x == 2 * y;
    //@ assert 2 * x == 8;
    //@ assert 2 * y == 8;
    
    return 0;
}

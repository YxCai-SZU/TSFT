/*@
    requires a > 0 && b > 0 && c > 0;
    requires a * a + b * b == c * c;
    ensures \result == 0;
    ensures a * a + b * b == c * c;
*/
int test_pythagorean_triple(int a, int b, int c) {
    //@ assert a * a >= 0;
    //@ assert b * b >= 0;
    //@ assert c * c >= 0;
    //@ assert a * a + b * b >= 0;
    //@ assert a * a + b * b <= c * c;
    
    return 0;
}

int main() {
    return 0;
}

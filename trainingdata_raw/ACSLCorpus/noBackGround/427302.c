/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    requires a != b;
    requires b != c;
    requires a != c;
    ensures \result == 0;
    ensures a != b && a != c && b != c;
*/
int example(int a, int b, int c) {
    //@ assert 1 <= a <= 10;
    //@ assert 1 <= b <= 10;
    //@ assert 1 <= c <= 10;
    //@ assert a != b && b != c && a != c;
    
    return 0;
}

int main() {
    return 0;
}

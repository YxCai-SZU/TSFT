/*@
    requires a <= b && b <= c;
    requires a >= 0 && b >= 0 && c >= 0;
    ensures \result == 1;
*/
int verify_ordered(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    return 1;
}

int main() {
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;
    
    //@ assert a <= b && b <= c;
    //@ assert a >= 0 && b >= 0 && c >= 0;
    
    int result = verify_ordered(a, b, c);
    return 0;
}

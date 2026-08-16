/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_transitivity(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 1;
}

int main() {
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
    
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    
    int result = verify_transitivity(a, b, c);
    return 0;
}

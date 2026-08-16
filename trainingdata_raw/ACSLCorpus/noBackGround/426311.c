/*@
    requires 1 <= a && a <= 5;
    requires 5 <= b && b <= 10;
    ensures \result == 0;
    ensures a <= b;
*/
int func(int a, int b) {
    //@ assert 1 <= a && a <= 5;
    //@ assert 5 <= b && b <= 10;
    //@ assert a <= b;
    return 0;
}

int main() {
    int a;
    int b;
    
    a = 3;
    b = 7;
    
    int result = func(a, b);
    
    return 0;
}

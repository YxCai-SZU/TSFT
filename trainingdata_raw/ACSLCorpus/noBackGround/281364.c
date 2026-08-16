/*@
    requires ((a) >= -1000 && (a) <= 1000 && (b) >= -1000 && (b) <= 1000);
    ensures \result <= 1000000;
*/
int func(int a, int b) {
    //@ assert ((a) >= -1000 && (a) <= 1000 && (b) >= -1000 && (b) <= 1000);
    
    //@ assert a >= -1000 && a <= 1000;
    //@ assert b >= -1000 && b <= 1000;
    
    //@ assert -1000000 <= a * b <= 1000000;
    
    int result = a * b;
    //@ assert result <= 1000000;
    
    return result;
}

int main() {
    return 0;
}

/*@
    requires ((a) > 0) && ((b) > 0);
    ensures \result == 0;
*/
int func(int a, int b) {
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert a + 3 * b < a + 4 * b;
    
    return 0;
}

int main() {
    return 0;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures 2 <= \result && \result <= 20;
*/
int example(int a, int b) {
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 2 <= a + b && a + b <= 20;
    return a + b;
}

int main() {
    return 0;
}

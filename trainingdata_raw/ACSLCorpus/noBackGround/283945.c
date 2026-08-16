/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures 2 * a + 3 * b <= 50;
    assigns \nothing;
*/
void example(int a, int b) {
    //@ assert 2 * a <= 20;
    //@ assert 3 * b <= 30;
    //@ assert 2 * a + 3 * b <= 50;
}

int main() {
    return 0;
}

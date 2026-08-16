/*@
    requires a > 0 && b > 0;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_example1(int a, int b) {
    //@ assert a * b == b * a;
    return 1;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_example2(int a, int b, int c) {
    //@ assert a * (b * c) == (a * b) * c;
    return 1;
}

/*@
    requires a > 0 && b > 0;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_example3(int a, int b) {
    //@ assert a * (a + b) == a * a + a * b;
    return 1;
}

/*@
    requires a > 0 && b > 0 && c > 0 && a <= 10 && b <= 10 && c <= 10;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_example4(int a, int b, int c) {
    //@ assert a * b <= 10 * 10;
    //@ assert a * b * c <= 10 * 10 * 10;
    return 1;
}

int main() {
    return 0;
}

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    requires 0 <= d && d <= 100;
    requires a <= b;
    requires c <= d;
    ensures \result == 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    //@ assert 0 <= d && d <= 100;
    //@ assert a <= b;
    //@ assert c <= d;
    //@ assert a * c <= 100 * 100;
    //@ assert b * d <= 100 * 100;
    //@ assert a * c <= b * d;
    return 1;
}

int main() {
    return 0;
}

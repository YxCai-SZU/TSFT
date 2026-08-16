/*@
    requires 0 <= a && a <= 100;
    ensures \result == (a >= 50);
    assigns \nothing;
*/
int func(int a) {
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= a;
    //@ assert a <= 100;
    return a >= 50;
}

int main() {
    return 0;
}

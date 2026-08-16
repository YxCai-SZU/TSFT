/*@
    requires 1 <= a && a <= 1;
    ensures \result == a;
    assigns \nothing;
*/
int division_iden(int a) {
    //@ assert 1 <= a && a <= 1;
    //@ assert a / 1 == a;
    return a / 1;
}

int main() {
    return 0;
}

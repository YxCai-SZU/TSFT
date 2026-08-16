/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a * 2 <= b);
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    return a * 2 <= b;
}

int main() {
    return 0;
}

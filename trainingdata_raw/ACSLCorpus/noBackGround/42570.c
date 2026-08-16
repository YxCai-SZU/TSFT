/*@
    requires 0 <= i <= 100;
    ensures \result == ((i) * 2);
    assigns \nothing;
*/
int compute_f(int i) {
    int result;
    //@ assert ((i) * 2) == i * 2;
    result = i * 2;
    //@ assert result == ((i) * 2);
    return result;
}

int main() {
    int x = 50;
    int y = compute_f(x);
    //@ assert y == 100;
    return 0;
}

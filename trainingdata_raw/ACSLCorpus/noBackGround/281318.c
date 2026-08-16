/*@
    requires 0 <= x && x <= 1;
    ensures \result == 0;
    assigns \nothing;
*/
int non_linear_example(int x) {
    //@ assert 0 <= x && x <= 1;
    //@ assert x * x <= 1;
    return 0;
}

int main() {
    return 0;
}

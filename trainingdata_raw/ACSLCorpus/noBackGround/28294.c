/*@
    requires ((x) >= 0);
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example(int x) {
    //@ assert x >= 0;
    //@ assert x <= x + 2 * x + 1;
    return 0;
}

int main() {
    return 0;
}

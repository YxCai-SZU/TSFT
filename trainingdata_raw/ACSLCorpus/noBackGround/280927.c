/*@
    requires a <= b;
    requires b == 6;
    ensures a <= 6;
*/
void calc_example_7(int a, int b) {
    //@ assert a <= b;
    //@ assert b == 6;
    //@ assert a <= 6;
}

int main() {
    return 0;
}

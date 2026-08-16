/*@
    requires x <= y;
    ensures -y <= -x;
*/
void calc_example_10(int x, int y) {
    //@ assert -y <= -x;
}

/*@
    requires x <= y;
    ensures -y <= -x;
*/
void calc_example_11(int x, int y) {
    //@ assert -y <= -x;
}

int main() {
    return 0;
}

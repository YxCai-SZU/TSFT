/*@
    requires x > 0;
    ensures \result == 1;
*/
int calc_example_4(int x) {
    //@ assert x * 2 <= x * 6;
    return 1;
}

int main() {
    return 0;
}

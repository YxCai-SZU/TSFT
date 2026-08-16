/*@
    requires x >= 0;
    ensures \result >= x;
*/
int calc_example_4(int x) {
    //@ assert x * 3 >= x;
    return x * 3;
}

int main() {
    return 0;
}

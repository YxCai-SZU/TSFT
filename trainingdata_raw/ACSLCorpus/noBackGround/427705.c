/*@
    requires x < y;
    ensures \result == 1;
*/
int example_5(int x, int y) {
    //@ assert x < y;
    //@ assert x * 2 < y * 2;
    return 1;
}

int main() {
    return 0;
}

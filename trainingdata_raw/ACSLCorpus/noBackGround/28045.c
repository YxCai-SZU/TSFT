/*@
requires ((x) > 0) && ((y) > 0);
ensures \result > 1;
*/
int example_7(int x, int y) {
    //@ assert ((x) > 0);
    //@ assert ((y) > 0);
    //@ assert x + 2 * y > 1;
    return x + 2 * y;
}

int main() {
    return 0;
}

/*@
    requires n > 0;
    ensures \result == 0;
    ensures ((n) < (n) + 2);
*/
int calc_example_7(int n) {
    //@ assert ((n) <= (n) + 1);
    //@ assert ((n) < (n) + 2);
    return 0;
}

int main() {
    return 0;
}

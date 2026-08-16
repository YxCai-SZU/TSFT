/*@
    requires a <= b;
    ensures \result == \true;
*/
int calc_example_10(int a, int b) {
    //@ assert 2 * a <= 2 * b;
    return 1;
}

/*@
    requires n > 10 && n % 2 == 0;
    ensures \result == 1;
*/
int is_even_and_greater_than_10(int n) {
    //@ assert n > 10;
    //@ assert n % 2 == 0;
    return 1;
}

int main() {
    return 0;
}

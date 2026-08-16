/*@
requires ((x) - (y) == (x) - (y));
ensures ((x) - (y) == (x) - (y));
*/
void axiom_subtraction(int x, int y) {
    //@ assert ((x) - (y) == (x) - (y));
}

/*@
requires ((a) == (b) - 1);
ensures ((a) - 1 == (b) - 2);
*/
void calc_example_8(int a, int b) {
    //@ assert ((a) == (b) - 1);
    //@ assert ((a) - 1 == (b) - 2);
}

/*@
requires ((x) + (y) == (z));
ensures ((x) == (z) - (y));
*/
void lemma_distributive(int x, int y, int z) {
    //@ assert ((x) + (y) == (z));
    //@ assert ((x) == (z) - (y));
}

/*@
requires ((a) == (b) + (c));
ensures ((a) - (c) == (b));
*/
void calc_example_10(int a, int b, int c) {
    //@ assert ((a) == (b) + (c));
    //@ assert ((a) - (c) == (b));
}

int main() {
    return 0;
}

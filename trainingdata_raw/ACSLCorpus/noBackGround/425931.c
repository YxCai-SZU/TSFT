/*@
requires ((x) == (y));
ensures ((x + 1) == (y + 1));
assigns \nothing;
*/
void calc_example_6(int x, int y) {
    //@ assert ((x) == (y));
    //@ assert ((x + 1) == (y + 1));
}

/*@
requires ((x) <= (y));
ensures ((x + 1) <= (y + 1));
assigns \nothing;
*/
void calc_example_7(int x, int y) {
    //@ assert ((x) <= (y));
    //@ assert ((x + 1) <= (y + 1));
}

/*@
requires ((x) >= (y));
ensures ((x + 1) >= (y + 1));
assigns \nothing;
*/
void calc_example_8(int x, int y) {
    //@ assert ((x) >= (y));
    //@ assert ((x + 1) >= (y + 1));
}

/*@
requires ((x) == (y));
ensures ((x + 1) == (y + 1));
assigns \nothing;
*/
void proof_example_9(int x, int y) {
    //@ assert ((x) == (y));
    //@ assert ((x + 1) == (y + 1));
}

/*@
requires ((x) <= (y));
ensures ((x + 1) <= (y + 1));
assigns \nothing;
*/
void proof_example_10(int x, int y) {
    //@ assert ((x) <= (y));
    //@ assert ((x + 1) <= (y + 1));
}

/*@
requires ((x) >= (y));
ensures ((x + 1) >= (y + 1));
assigns \nothing;
*/
void proof_example_11(int x, int y) {
    //@ assert ((x) >= (y));
    //@ assert ((x + 1) >= (y + 1));
}

int main() {
    return 0;
}

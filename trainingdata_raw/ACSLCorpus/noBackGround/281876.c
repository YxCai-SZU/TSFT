/*@
    requires ((a) < (b)) && ((b) < (c));
    ensures ((a) <= (c));
*/
void calc_example_3(int a, int b, int c) {
    //@ assert ((a) < (b));
    //@ assert ((b) < (c));
    //@ assert ((a) <= (c));
}

/*@
    requires ((a) < (b)) && ((b) < (c));
    ensures ((a) <= (c));
*/
void calc_example_4(int a, int b, int c) {
    //@ assert ((a) < (b));
    //@ assert ((b) < (c));
    //@ assert ((a) <= (c));
}

int main() {
    return 0;
}

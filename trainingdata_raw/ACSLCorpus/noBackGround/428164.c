/*@
    requires x == y;
    ensures \result == 1;
    assigns \nothing;
*/
int example_1(int x, int y) {
    //@ assert x == y;
    //@ assert x * 2 == y * 2;
    return 1;
}

/*@
    requires x == y;
    ensures \result == 1;
    assigns \nothing;
*/
int example_2(int x, int y) {
    //@ assert x == y;
    //@ assert x * 4 == y * 4;
    return 1;
}

/*@
    requires x == y;
    ensures \result == 1;
    assigns \nothing;
*/
int example_3(int x, int y) {
    //@ assert x == y;
    //@ assert x * 8 == y * 8;
    return 1;
}

int main() {
    return 0;
}

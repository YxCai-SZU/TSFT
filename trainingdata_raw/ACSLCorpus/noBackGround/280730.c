/*@
requires a <= b && b < c;
ensures \result == 1;
assigns \nothing;
*/
int strict_transitivity(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b < c;
    //@ assert a < c;
    return 1;
}

int main() {
    return 0;
}

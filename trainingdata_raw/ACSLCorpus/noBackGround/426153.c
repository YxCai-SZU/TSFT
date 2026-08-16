/*@
requires a >= b && b >= 0;
ensures \result >= 0;
*/
int greater_than_or_equal(int a, int b) {
    //@ assert a >= b;
    //@ assert b >= 0;
    return a;
}

/*@
requires a <= b && b <= 0;
ensures \result <= 0;
*/
int less_than_or_equal(int a, int b) {
    //@ assert a <= b;
    //@ assert b <= 0;
    return a;
}

int main() {
    return 0;
}

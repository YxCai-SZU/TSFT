/*@
requires a <= b;
ensures \result == 0;
*/
int calc_context_example_1(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
requires x <= y && y <= z;
ensures \result == 0;
*/
int calc_context_example_2(int x, int y, int z) {
    //@ assert x <= z;
    return 0;
}

/*@
requires a <= b && (a == b || a + 1 == b || a + 2 == b || a + 3 == b);
ensures \result == 0;
*/
int calc_context_example_3(int a, int b) {
    //@ assert b <= a + 3;
    return 0;
}

/*@
requires a <= b && b <= a + 2;
ensures \result == 0;
*/
int calc_context_example_4(int a, int b) {
    //@ assert b <= a + 2;
    return 0;
}

int main() {
    return 0;
}

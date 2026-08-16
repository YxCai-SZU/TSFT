/*@
    requires a <= b;
    requires b - a <= 5;
    ensures \result == 0;
    ensures a + 3 <= b + 3;
*/
int arithmetic_example(int a, int b) {
    //@ assert a <= b;
    //@ assert b - a <= 5;
    //@ assert a + 3 <= b + 3;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    ensures a <= b;
*/
int comparison_example(int a, int b) {
    //@ assert a <= b;
    return 0;
}

int main() {
    return 0;
}

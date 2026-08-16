/*@
    requires ((a) <= (b));
    ensures \result == 1;
*/
int func(int a, int b) {
    //@ assert ((a) <= (b));
    //@ assert ((a + 1) <= (b + 1));
    return 1;
}

/*@
    requires ((a) <= (b));
    ensures \result == 1;
*/
int func2(int a, int b) {
    //@ assert ((a) <= (b));
    //@ assert ((a + 2) <= (b + 2));
    return 1;
}

/*@
    requires ((a) <= (b));
    ensures \result == 1;
*/
int func3(int a, int b) {
    //@ assert ((a) <= (b));
    //@ assert ((a - 2) <= (b - 2));
    return 1;
}

/*@
    requires ((a) <= (b));
    ensures \result == 1;
*/
int func4(int a, int b) {
    //@ assert ((a) <= (b));
    //@ assert ((a * 3) <= (b * 3));
    return 1;
}

int main() {
    return 0;
}

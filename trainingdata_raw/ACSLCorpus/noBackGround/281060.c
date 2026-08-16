void main() {
    // Empty main function as per original code
}

/*@
    requires a == b;
    ensures \result == 0;
*/
int calc_example_6(int a, int b) {
    //@ assert a == b;
    return 0;
}

/*@
    requires a == b;
    ensures \result == 0;
*/
int example_and_assign(int a, int b) {
    //@ assert a == b;
    //@ assert a == b;
    //@ assert a == b;
    return 0;
}

/*@
    requires a == b;
    ensures \result == 0;
*/
int example_and_assign_2(int a, int b) {
    //@ assert a == b;
    //@ assert a == b;
    //@ assert a == b;
    return 0;
}

/*@
    requires a == b;
    ensures \result == 0;
*/
int loop_isolation_example(int a, int b) {
    //@ assert a == b;
    //@ assert a == b;
    //@ assert a == b;
    return 0;
}

/*@
    requires a == b;
    ensures \result == 0;
*/
int loop_isolation_example_2(int a, int b) {
    //@ assert a == b;
    //@ assert a == b;
    //@ assert a == b;
    return 0;
}

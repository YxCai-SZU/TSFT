/*@
    requires ((x) > 5);
    ensures ((x) - 3 > 0);
    ensures ((x) - 3 <= (x));
*/
void assertion(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 > 0);
    //@ assert ((x) - 3 <= (x));
}

/*@
    requires ((x) > 5);
    ensures ((x) - 3 > 0);
*/
void subtraction_correctness(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 > 0);
}

/*@
    requires ((x) > 5);
    ensures ((x) - 3 <= (x));
*/
void subtraction_is_not_greater_than(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 <= (x));
}

/*@
    requires ((x) > 5);
    ensures ((x) - 3 <= (x));
*/
void subtraction_is_not_greater_than_2(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 <= (x));
}

/*@
    requires ((x) > 5);
    ensures ((x) - 3 > 0);
*/
void subtraction_is_greater_than_2(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 > 0);
}

/*@
    requires ((x) > 5);
    ensures ((x) - 3 > 0);
*/
void subtraction_is_greater_than_3(int x) {
    //@ assert ((x) > 5);
    //@ assert ((x) - 3 > 0);
}

int main() {
    return 0;
}

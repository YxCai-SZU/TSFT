/*@
requires \true;
ensures ((a) == (a));
*/
void proof_no_op_idempotent(int a) {
    //@ assert ((a) == (a));
}

/*@
requires \true;
ensures ((a) + (b) == (b) + (a));
*/
void proof_addition_commutes(int a, int b) {
    //@ assert ((a) + (b) == (b) + (a));
}

/*@
requires \true;
ensures ((a) - (b) == -((b) - (a)));
*/
void proof_subtraction_commutes(int a, int b) {
    //@ assert ((a) - (b) == -((b) - (a)));
}

/*@
requires a == b;
ensures a == b - 0;
*/
void proof_calc_example_1(int a, int b) {
    //@ assert a == b;
    //@ assert a == b - 0;
}

/*@
requires a == b;
ensures a + 0 == b + 0;
*/
void proof_calc_example_2(int a, int b) {
    //@ assert a == b;
    //@ assert a + 0 == b + 0;
}

/*@
requires a == b;
ensures a - 0 == b - 0;
*/
void proof_calc_example_3(int a, int b) {
    //@ assert a == b;
    //@ assert a - 0 == b - 0;
}

/*@
requires a == b;
ensures a + 1 == b + 1;
*/
void proof_calc_example_4(int a, int b) {
    //@ assert a == b;
    //@ assert a + 1 == b + 1;
}

/*@
requires a == b;
ensures a - 1 == b - 1;
*/
void proof_calc_example_5(int a, int b) {
    //@ assert a == b;
    //@ assert a - 1 == b - 1;
}

int main() {
    return 0;
}

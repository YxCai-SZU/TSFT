/*@
    lemma division_property: \forall integer a, b; a >= 0 && b > 0 ==> a / b * b + a % b == a;
*/

/*@
    requires a >= 0 && b > 0;
    ensures \result == a / b * b + a % b;
    assigns \nothing;
*/
int nonlinear_arith_example19(int a, int b) {
    //@ assert a >= 0 && b > 0;
    int result = a / b * b + a % b;
    //@ assert result == a;
    return result;
}

/*@
    requires a >= 0 && b > 0;
    ensures \result == a / b * b + a % b;
    assigns \nothing;
*/
int nonlinear_arith_example20(int a, int b) {
    //@ assert a >= 0 && b > 0;
    int result = a / b * b + a % b;
    //@ assert result == a;
    return result;
}

/*@
    requires a >= 0 && b > 0;
    ensures \result == a / b * b + a % b;
    assigns \nothing;
*/
int nonlinear_arith_example21(int a, int b) {
    //@ assert a >= 0 && b > 0;
    int result = a / b * b + a % b;
    //@ assert result == a;
    return result;
}

int main() {
    return 0;
}

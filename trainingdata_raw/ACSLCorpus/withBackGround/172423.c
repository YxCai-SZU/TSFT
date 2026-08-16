/*@
    predicate non_negative(integer a, integer b) = a >= 0 && b >= 0;
    predicate sum_constraint(integer a, integer b) = a + b <= 10;
    
    lemma calc_example_9: \forall integer a, b; non_negative(a, b) && sum_constraint(a, b) ==> a * 2 == 2 * a;
    lemma calc_example_10: \forall integer a, b; non_negative(a, b) && sum_constraint(a, b) ==> a * 2 <= 2 * a;
    lemma calc_example_11: \forall integer a, b; non_negative(a, b) && sum_constraint(a, b) ==> a * 2 >= 2 * a;
    lemma func_inequality: \forall integer a, b; non_negative(a, b) && sum_constraint(a, b) ==> a * 2 <= a * 2;
*/

/*@
    requires a >= 0 && b >= 0;
    requires a + b <= 10;
    ensures \result == 0;
*/
int verify_calc_example_9(int a, int b) {
    //@ assert a * 2 == 2 * a;
    return 0;
}

/*@
    requires a >= 0 && b >= 0;
    requires a + b <= 10;
    ensures \result == 0;
*/
int verify_calc_example_10(int a, int b) {
    //@ assert a * 2 <= 2 * a;
    return 0;
}

/*@
    requires a >= 0 && b >= 0;
    requires a + b <= 10;
    ensures \result == 0;
*/
int verify_calc_example_11(int a, int b) {
    //@ assert a * 2 >= 2 * a;
    return 0;
}

/*@
    requires a >= 0 && b >= 0;
    requires a + b <= 10;
    ensures \result == 0;
*/
int verify_func_inequality(int a, int b) {
    //@ assert a * 2 <= a * 2;
    return 0;
}

int main() {
    return 0;
}

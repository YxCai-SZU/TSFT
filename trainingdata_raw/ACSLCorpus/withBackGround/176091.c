/*@
    predicate multiplication_positive(integer x) = x > 5 ==> x * 3 > 0;
    predicate subtraction_positive(integer x) = x > 5 ==> x - 3 > 0;
    predicate sqrt_range(integer x) = x >= 0 && x <= 65535;

    lemma multiplication_correctness: \forall integer x; x > 5 ==> x * 3 > 0;
    lemma subtraction_correctness: \forall integer x; x > 5 ==> x - 3 > 0;
    lemma sqrt_bounds: \forall integer x; x >= 0 && x <= 65535 ==> x >= 0 && x <= 65535;
*/

/*@
    requires x > 5;
    ensures \result > 0;
*/
int multiply_by_three(int x) {
    int result;
    //@ assert x > 5;
    result = x * 3;
    //@ assert result > 0;
    return result;
}

/*@
    requires x > 5;
    ensures \result > 0;
*/
int subtract_three(int x) {
    int result;
    //@ assert x > 5;
    result = x - 3;
    //@ assert result > 0;
    return result;
}

/*@
    requires x >= 0 && x <= 65535;
    ensures \result >= 0 && \result <= 65535;
*/
int sqrt_bounds_check(int x) {
    int result;
    //@ assert x >= 0 && x <= 65535;
    result = x;
    //@ assert result >= 0 && result <= 65535;
    return result;
}

int main() {
    return 0;
}

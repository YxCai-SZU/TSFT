/*@
    predicate identity(integer n) = n == n;

    lemma identity_lemma: \forall integer n; identity(n);
    lemma comparison_lemma: \forall integer n; n == 10 ==> n <= 15;
    lemma addition_lemma: \forall integer n; n == 10 ==> n + 3 == 13;
    lemma multiplication_lemma: \forall integer n; n == 10 ==> n * 3 == 30;
    lemma subtraction_lemma: \forall integer n; n == 10 ==> n - 3 == 7;
    lemma calc_example_5_lemma: \forall integer n; n == 10 ==> n * 2 == 20;
    lemma calc_example_6_lemma: \forall integer n; n == 10 ==> n * 2 <= 20;
    lemma calc_example_7_lemma: \forall integer n; n == 10 ==> n + 3 <= 15;
    lemma calc_example_8_lemma: \forall integer n; n == 10 ==> n * 3 <= 30;
    lemma calc_example_9_lemma: \forall integer n; n == 10 ==> n - 3 <= 7;
*/

/*@
    requires n == 10;
    ensures \result == 10;
*/
int lemma_identity(int n) {
    //@ assert n == n;
    return n;
}

/*@
    requires n == 10;
    ensures \result <= 15;
*/
int lemma_comparison(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result <= 15;
    return result;
}

/*@
    requires n == 10;
    ensures \result == 13;
*/
int lemma_addition(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result + 3 == 13;
    return result + 3;
}

/*@
    requires n == 10;
    ensures \result == 30;
*/
int lemma_multiplication(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result * 3 == 30;
    return result * 3;
}

/*@
    requires n == 10;
    ensures \result == 7;
*/
int lemma_subtraction(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result - 3 == 7;
    return result - 3;
}

/*@
    requires n == 10;
    ensures \result == 20;
*/
int calc_example_5(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result * 2 == 20;
    return result * 2;
}

/*@
    requires n == 10;
    ensures \result <= 20;
*/
int calc_example_6(int n) {
    int result;
    result = lemma_identity(n);
    //@ assert result * 2 <= 20;
    return result * 2;
}

/*@
    requires n == 10;
    ensures \result <= 15;
*/
int calc_example_7(int n) {
    int result;
    result = lemma_addition(n);
    //@ assert result <= 15;
    return result;
}

/*@
    requires n == 10;
    ensures \result <= 30;
*/
int calc_example_8(int n) {
    int result;
    result = lemma_multiplication(n);
    //@ assert result <= 30;
    return result;
}

/*@
    requires n == 10;
    ensures \result <= 7;
*/
int calc_example_9(int n) {
    int result;
    result = lemma_subtraction(n);
    //@ assert result <= 7;
    return result;
}

int main() {
    return 0;
}

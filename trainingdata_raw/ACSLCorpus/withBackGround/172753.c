/*@
    predicate inequality_condition(integer i, integer j) =
        i <= j && j < i + 3;

    lemma inequality_lemma:
        \forall integer i, j;
            inequality_condition(i, j) ==> i <= j + 1 * 3;

    lemma calc_example_lemma:
        \forall integer n;
            n >= 0 ==> n + 1 <= n + 3;
*/

/*@
    requires n >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_6(int n) {
    //@ assert n >= 0;
    //@ assert n + 1 <= n + 3;
    return 1;
}

/*@
    requires i <= j;
    requires j < i + 3;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_inequality(int i, int j) {
    //@ assert i <= j;
    //@ assert j < i + 3;
    //@ assert i <= j + 1 * 3;
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

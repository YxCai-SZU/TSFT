/*@
    predicate add_three_holds(integer n) = n + 3 > n;
    predicate add_four_holds(integer n) = n + 4 > n;
    predicate add_six_holds(integer n) = n + 6 > n;
    predicate sub_two_holds(integer n) = n - 2 < n;
    predicate sub_one_holds(integer n) = n - 1 < n;

    lemma calc_example_12: \forall integer n, m; n + 1 == m ==> 2 * n + 2 == 2 * m;
    lemma lemma_add_three: \forall integer n; add_three_holds(n) ==> add_three_holds(n);
    lemma lemma_add_four: \forall integer n; add_four_holds(n) ==> add_four_holds(n);
    lemma lemma_add_six: \forall integer n; add_six_holds(n) ==> add_six_holds(n);
    lemma lemma_sub_two: \forall integer n; sub_two_holds(n) ==> sub_two_holds(n);
    lemma lemma_sub_one: \forall integer n; sub_one_holds(n) ==> sub_one_holds(n);
*/

/*@
    requires n + 1 == m;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_12(int n, int m) {
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
    return 0;
}

/*@
    requires n + 3 > n;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_add_three(int n) {
    //@ assert n + 3 > n;
    return 0;
}

/*@
    requires n + 4 > n;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_add_four(int n) {
    //@ assert n + 4 > n;
    return 0;
}

/*@
    requires n + 6 > n;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_add_six(int n) {
    //@ assert n + 6 > n;
    return 0;
}

/*@
    requires n - 2 < n;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_sub_two(int n) {
    //@ assert n - 2 < n;
    return 0;
}

/*@
    requires n - 1 < n;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_sub_one(int n) {
    //@ assert n - 1 < n;
    return 0;
}

int main() {
    return 0;
}

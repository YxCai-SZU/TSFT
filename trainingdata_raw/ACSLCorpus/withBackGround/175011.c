/*@
    predicate sorted(integer a, integer b, integer c) = a <= b && b <= c;
    predicate sorted_or_equal(integer a, integer b, integer c) = sorted(a, b, c) || (a == b && a == c);
    predicate pairwise_distinct(integer a, integer b, integer c) = a != b && b != c && a != c;
    predicate all_distinct(integer a, integer b, integer c) = a != b && b != c && a != c;
*/

/*@
    lemma sorted_implies_sorted_or_equal: \forall integer a, b, c; sorted(a, b, c) ==> sorted_or_equal(a, b, c);
    lemma pairwise_eq_all_distinct: \forall integer a, b, c; pairwise_distinct(a, b, c) ==> all_distinct(a, b, c);
*/

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int check_sorted(int a, int b, int c) {
    //@ assert sorted(a, b, c);
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int check_sorted_or_equal(int a, int b, int c) {
    //@ assert sorted_or_equal(a, b, c);
    return 1;
}

/*@
    requires a != b && b != c && a != c;
    ensures \result == 1;
    assigns \nothing;
*/
int check_distinct(int a, int b, int c) {
    //@ assert pairwise_distinct(a, b, c);
    //@ assert all_distinct(a, b, c);
    return 1;
}

int main() {
    return 0;
}

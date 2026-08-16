/*@
predicate multiplication_commutative(integer a, integer b, integer c) =
    a * b == c && b * a == c;

lemma calc_multiplication_example:
    \forall integer a, b, c;
    multiplication_commutative(a, b, c) ==> a * b == b * a;

predicate transitive_relation(integer a, integer b, integer c) =
    a <= b && b <= c;

lemma calc_transitive_example:
    \forall integer a, b, c;
    transitive_relation(a, b, c) ==> a <= c;

predicate complex_constraint(integer a, integer b, integer c) =
    a <= b && b <= c && c <= a + 2;

lemma calc_complex_example:
    \forall integer a, b, c;
    complex_constraint(a, b, c) ==> a <= c && c <= a + 2;

predicate multiple_relations(integer a, integer b, integer c) =
    a <= b && b == c;

lemma calc_multiple_rels_example:
    \forall integer a, b, c;
    multiple_relations(a, b, c) ==> a <= c;

predicate equivalence(integer a, integer b) =
    a == b;

lemma calc_equivalence_example:
    \forall integer a, b;
    equivalence(a, b) ==> a <= b;

predicate non_equal_relation(integer a, integer b) =
    a <= b && b <= a + 1;

lemma calc_noneq_example:
    \forall integer a, b;
    non_equal_relation(a, b) ==> a <= b && b <= a + 1;
*/

int main() {
    return 0;
}

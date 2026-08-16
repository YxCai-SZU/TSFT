/*@
    predicate multiple_intermediate_relations_lemma(integer a, integer b) =
        a == b && b < a + 2 ==> a <= b + 1 * 2;

    predicate complex_multiple_intermediate_relations_lemma(integer a, integer b) =
        a == b && b < a + 3 ==> a <= b + 1 * 3;

    predicate assertions_example_lemma(integer x) =
        2 * x == x + x && x > 0 ==> x * 2 == x + x;

    predicate complex_assertions_example_lemma(integer x) =
        2 * x == x + x && x > 0 ==> x * 2 == x + x;

    predicate simple_relations_lemma(integer x) =
        2 * x == x + x ==> x * 2 == x + x;

    predicate complex_relations_lemma(integer x) =
        2 * x == x + x && x > 0 ==> x * 2 == x + x;
*/

/*@
    lemma multiple_intermediate_relations:
        \forall integer a, b; multiple_intermediate_relations_lemma(a, b);

    lemma complex_multiple_intermediate_relations:
        \forall integer a, b; complex_multiple_intermediate_relations_lemma(a, b);

    lemma assertions_example:
        \forall integer x; assertions_example_lemma(x);

    lemma complex_assertions_example:
        \forall integer x; complex_assertions_example_lemma(x);

    lemma simple_relations:
        \forall integer x; simple_relations_lemma(x);

    lemma complex_relations:
        \forall integer x; complex_relations_lemma(x);
*/

int main() {
    return 0;
}

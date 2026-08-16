/*@
    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;

    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;

    lemma calc_example_logical_layers:
        \forall boolean a, b, c;
            a == \true && b == \true && c == \true ==>
            (a && b) == (b && c);

    lemma is_strictly_increasing:
        \forall integer a, b, c;
            a < b && b < c ==> strictly_increasing(a, b, c);

    lemma is_strictly_decreasing:
        \forall integer a, b, c;
            a > b && b > c ==> strictly_decreasing(a, b, c);

    lemma equality_example:
        \forall integer a, b;
            a == b ==> a == b;

    lemma inequality_example:
        \forall integer a, b;
            a < b ==> a < b;

    lemma nontrivial_example:
        \forall integer a, b;
            a < b && b < 5 ==> a < 5;

    lemma nontrivial_example2:
        \forall integer a, b;
            a > b && b > 5 ==> a > 5;
*/

int main() {
    return 0;
}

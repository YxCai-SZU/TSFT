/*@
    predicate pos(integer v) = v > 0;

    lemma common_example:
        \forall integer x, y; pos(x) && pos(y) ==> x * y > 0;

    lemma communicative_example:
        \forall integer x, y; pos(x) && pos(y) ==> x * y == y * x;

    lemma associative_example:
        \forall integer x, y, z; pos(x) && pos(y) && pos(z) ==> x * (y * z) == (x * y) * z;

    lemma distributive_add_example:
        \forall integer x, y, z; pos(x) && pos(y) && pos(z) ==> x * (y + z) == x * y + x * z;

    lemma example_5:
        \forall integer x, y; pos(x) && pos(y) ==> x * y == y * x;

    lemma example_6:
        \forall integer x, y; pos(x) && pos(y) ==> x * (y * x) == (x * y) * x;
*/

int main() {
    return 0;
}

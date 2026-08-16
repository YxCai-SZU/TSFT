/*@
    predicate pos(integer v) = v > 0;

    lemma calc_example_5:
        \forall integer y; pos(y) ==> y * 2 >= y;

    lemma calc_example_6:
        \forall integer x, y; pos(x) && pos(y) ==> x * 2 + y * 2 >= x + y;

    lemma product_progression_3:
        \forall integer x, y, z; pos(x) && pos(y) && pos(z) ==> x * 3 >= x;
*/

int main() {
    return 0;
}

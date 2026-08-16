/*@
    predicate non_negative(integer x) = x >= 0;

    lemma inequality: \forall integer x; non_negative(x) ==> x <= x + 3;
    lemma trivial_equality: \forall integer x; x == x;
    lemma trivial_inequality: \forall integer x; x <= x + 1;
    lemma reverse_inequality: \forall integer x; non_negative(x) ==> x >= x - 1;
    lemma bidirectional_inequality: \forall integer x; non_negative(x) ==> x <= x + 1 && x >= x - 1;
*/

int main() {
    return 0;
}

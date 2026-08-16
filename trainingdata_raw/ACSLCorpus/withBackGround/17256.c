/*@
    predicate pos(integer a) = a > 0;

    lemma calc_example_6: \forall integer a; pos(a) ==> a <= a + 10;
    lemma verify_linearity: \forall integer a; pos(a) ==> a + a <= a + a + a;
    lemma verify_monotonic: \forall integer a; pos(a) ==> a <= a + 5;
    lemma verify_monotonic2: \forall integer a; pos(a) ==> a <= a + 10;
*/

int main() {
    return 0;
}

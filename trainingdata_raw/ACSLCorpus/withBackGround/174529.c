/*@
    predicate lower_bound(integer a) = a >= 0;
    predicate upper_bound(integer a) = a <= 100;
 */

/*@
    lemma calc_example_7: \forall integer a; a == a + 1 - 1;
    lemma calc_example_8: \forall integer a; lower_bound(a) && upper_bound(a) ==> a == a + 1 - 1;
    lemma calc_example_9: \forall integer a; lower_bound(a) && upper_bound(a) ==> a == a + 2 - 1 - 1;
 */

int main() {
    return 0;
}

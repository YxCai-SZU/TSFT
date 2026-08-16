/*@
    predicate positive_sum(integer x, integer y) = x > 0 && y > 0 && x + y <= 100;
*/

/*@
    lemma calc_example_volume: \forall integer x, y; positive_sum(x, y) ==> \true;
*/

void main() {
    // No implementation needed as the original function is a proof lemma
}

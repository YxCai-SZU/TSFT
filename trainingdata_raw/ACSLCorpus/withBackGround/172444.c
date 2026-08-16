/*@
predicate g(integer i, integer j) = i >= 0 && j >= 0 && i + j <= 3;

lemma lemma_g_proves_f:
    \forall integer i, integer j; g(i, j) ==> \true;

lemma test_g_proves_f:
    \forall integer i; (\exists integer j; g(i, j)) ==> \true;
*/

int main() {
    return 0;
}

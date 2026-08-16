/*@
    logic integer f(integer x) = x * 2;

    predicate exists_f(integer i) = \exists integer j; f(j) == i;

    lemma test_exists_f: \forall integer i; exists_f(i) ==> i % 2 == 0;
    lemma lemma_even_f: \forall integer k; k % 2 == 0 ==> f(k) % 2 == 0;
*/

int main() {
    return 0;
}

/*@
predicate leq_int(integer A, integer B) = A <= B;

lemma lemma_assoc:
    \forall integer A, B, C;
        leq_int(A, B) && leq_int(B, C) ==> leq_int(A, C);

lemma lemma_add_is_monotonic_int:
    \forall integer A, B;
        leq_int(A, B) ==> leq_int(A + 1, B + 1);

lemma lemma_add_is_monotonic_int_2:
    \forall integer A, B, C;
        leq_int(A, B) && leq_int(B, C) ==> leq_int(A + 1, C + 1);

lemma lemma_monotonic_leq_int:
    \forall integer A, B, C;
        leq_int(A, B) && leq_int(B, C) ==> leq_int(A, C);

lemma lemma_monotonic_leq:
    \forall integer A, B;
        leq_int(A, B) ==> leq_int(A, B + 1);

lemma lemma_monotonic_leq_strict:
    \forall integer A, B;
        leq_int(A, B) ==> leq_int(A, B + 1);

lemma lemma_monotonic_leq_strict_2:
    \forall integer A, B, C;
        leq_int(A, B) && leq_int(B, C) ==> leq_int(A, C + 1);

lemma lemma_monotonic_leq_strict_3:
    \forall integer A, B, C;
        leq_int(A, B) && leq_int(B, C) ==> leq_int(A, C + 1);
*/

int main() {
    return 0;
}

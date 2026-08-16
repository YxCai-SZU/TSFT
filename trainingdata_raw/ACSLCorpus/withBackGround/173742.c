/*@
predicate positive(integer x) = x > 0;

lemma positive_is_positive:
    \forall integer x; positive(x) ==> positive(x);

lemma positive_is_strictly_increasing:
    \forall integer x, y; x < y && positive(x) ==> positive(x);

lemma positive_is_monotonic:
    \forall integer x, y; x < y && positive(x) ==> positive(x);

lemma positive_is_greater_than_negative:
    \forall integer x, y; positive(x) && y < 0 ==> positive(x);

lemma positive_is_greater_than_zero:
    \forall integer x; positive(x) ==> positive(x);

lemma positive_is_positive_or_zero:
    \forall integer x; x >= 0 ==> (positive(x) || x == 0);
*/

void main() {
    // No implementation needed for proof lemmas
}

/*@
    predicate le(integer x, integer y) = x <= y;
    predicate lt(integer x, integer y) = x < y;
    predicate eq(integer x, integer y) = x == y;

    lemma calc_combined_example_1: \forall integer x, y, z; le(x, y) && le(y, z) ==> le(x, z);
    lemma calc_combined_example_2: \forall integer x, y, z; lt(x, y) && lt(y, z) ==> lt(x, z);
    lemma calc_combined_example_3: \forall integer x, y, z; eq(x, y) && eq(y, z) ==> eq(x, z);

    lemma proof_example_1: \forall integer a, b; 0 <= a && le(a, b) && le(b, 5) ==> 0 <= b;
    lemma proof_example_2: \forall integer a, b; 0 <= a && le(a, b) && le(b, 5) ==> 0 <= b;
    lemma proof_example_3: \forall integer a, b; 0 <= a && le(a, b) && le(b, 5) ==> 0 <= b;
*/

void main() {
    // No implementation needed for proof functions
}

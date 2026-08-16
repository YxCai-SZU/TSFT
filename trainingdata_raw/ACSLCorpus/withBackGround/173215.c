/*@
predicate le_int(integer a, integer b) = a <= b;

lemma calc_example_20: \forall integer x, y, z; le_int(x, y) && le_int(y, z) ==> le_int(x, z);
lemma check_subtraction: \forall integer x, y; le_int(x, y) ==> 0 <= y - x;
lemma mainproof: \forall integer x, y; le_int(x, y) ==> le_int(x, y + 0);
*/

void main() {
    // No implementation needed for proof functions
}

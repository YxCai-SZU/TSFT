/*@
predicate equal(integer a, integer b) = a == b;

lemma calc_example_9: \forall integer x, y, z; equal(x, y) && equal(y, z) ==> x * 3 == z * 3;
lemma calc_example_10: \forall integer a, b; equal(a, b) ==> a * 2 == b * 2;
lemma calc_example_11: \forall integer x, y; equal(x, y) ==> x * 4 == y * 4;
lemma calc_example_12: \forall integer x, y; equal(x, y) ==> x * 8 == y * 8;
lemma calc_example_13: \forall integer x, y; equal(x, y) ==> x * 16 == y * 16;
lemma calc_example_14: \forall integer x, y; equal(x, y) ==> x * 32 == y * 32;
*/

int main() {
    return 0;
}

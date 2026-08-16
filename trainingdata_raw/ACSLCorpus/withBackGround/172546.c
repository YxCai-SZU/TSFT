/*@
predicate nonnegative(integer x) = x >= 0;

lemma calc_example_3: \forall integer x; nonnegative(x) ==> x * 2 >= x;

lemma proof_add_comm: \forall integer x, y; nonnegative(x) && nonnegative(y) ==> x + y == y + x;

lemma proof_add_assoc: \forall integer x, y, z; nonnegative(x) && nonnegative(y) && nonnegative(z) ==> (x + y) + z == x + (y + z);

lemma proof_add_monotonic: \forall integer x, y, z; nonnegative(x) && nonnegative(y) && nonnegative(z) && x <= y ==> x + z <= y + z;
*/

int main() {
    return 0;
}

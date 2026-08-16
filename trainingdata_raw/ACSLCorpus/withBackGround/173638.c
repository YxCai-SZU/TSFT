/*@
predicate equal(integer a, integer b) = a == b;

lemma double_equality: \forall integer a, b; equal(a, b) ==> a * 2 == b * 2;
lemma sum_of_equality: \forall integer a, b; equal(a, b) ==> a + b == 2 * a;
lemma product_equality: \forall integer a, b; equal(a, b) ==> a * b == a * a;
lemma combined_equality: \forall integer a, b; equal(a, b) ==> a * b + b * a == 2 * a * a;
lemma example_n: \forall integer a, b, c; equal(a, b) && equal(b, c) ==> equal(a, c);
lemma example_y: \forall integer a, b; equal(a, b) ==> a == a + 1 - 1 && a + 1 - 1 == a && equal(a, b);
lemma example_x: \forall integer a, b; equal(a, b) ==> equal(a, b);
lemma func_example: \forall integer a, b; equal(a, b) ==> equal(a, b);
lemma ensures_example: \forall integer a, b; equal(a, b) ==> equal(a, b);
lemma example_n_n: \forall integer a, b; equal(a, b) ==> equal(a, b);
*/

int main() {
    return 0;
}

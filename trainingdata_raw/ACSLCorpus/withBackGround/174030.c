/*@
    predicate nonnegative(integer a) = a >= 0;
    predicate nonnegative_pair(integer a, integer b) = a >= 0 && b >= 0;
    predicate b_nonzero(integer b) = b != 0;
*/

/*@
    lemma calc_example_11: \forall integer a, b; a <= b ==> a <= b + 1;
    lemma check_bounds: \forall integer a, b; a <= b && b + 1 >= a + 1 ==> a + 1 <= b + 1;
    lemma lemma_plus: \forall integer a, b; nonnegative_pair(a, b) && a + b <= 2 * a ==> a + b <= 2 * a;
    lemma lemma_times: \forall integer a, b; nonnegative_pair(a, b) && a * b <= a + b ==> a * b <= a + b;
    lemma lemma_minus: \forall integer a, b; nonnegative_pair(a, b) && a - b <= a ==> a - b <= a;
    lemma lemma_div: \forall integer a, b; nonnegative_pair(a, b) && b_nonzero(b) && a / b <= a ==> a / b <= a;
    lemma lemma_mod: \forall integer a, b; nonnegative_pair(a, b) && b_nonzero(b) && a % b <= a ==> a % b <= a;
    lemma lemma_add_increasing: \forall integer a, b; nonnegative_pair(a, b) && a + b <= 2 * a ==> a + b <= 2 * a;
    lemma lemma_add_decreasing: \forall integer a, b; nonnegative_pair(a, b) && a + b <= 2 * b ==> a + b <= 2 * b;
    lemma lemma_max: \forall integer a, b; nonnegative_pair(a, b) && a >= b ==> a >= b;
    lemma lemma_min: \forall integer a, b; nonnegative_pair(a, b) && a <= b ==> a <= b;
    lemma lemma_abs: \forall integer a, b; nonnegative_pair(a, b) && a >= b ==> a >= b;
    lemma lemma_max_decreasing: \forall integer a, b; nonnegative_pair(a, b) && a <= b ==> a <= b;
    lemma lemma_min_increasing: \forall integer a, b; nonnegative_pair(a, b) && a >= b ==> a >= b;
    lemma lemma_abs_decreasing: \forall integer a, b; nonnegative_pair(a, b) && a <= b ==> a <= b;
    lemma lemma_abs_increasing: \forall integer a, b; nonnegative_pair(a, b) && a >= b ==> a >= b;
*/

int main() {
    return 0;
}

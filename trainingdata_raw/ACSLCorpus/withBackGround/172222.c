/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_positive(integer x) = x > 0;

    lemma func_example_6: \forall integer n; is_even(n) && is_positive(n) ==> n + 2 > n;
    lemma func_example_7: \forall integer a, b; is_even(a) && is_even(b) && is_positive(a) && is_positive(b) ==> a + b + 2 > a + b;
    lemma func_example_8: \forall integer n; is_even(n) && is_positive(n) ==> n + 4 > n;
    lemma func_example_9: \forall integer a, b; is_even(a) && is_even(b) && is_positive(a) && is_positive(b) ==> a + b + 4 > a + b;
    lemma func_example_10: \forall integer n; is_even(n) && is_positive(n) ==> n + 6 > n;
    lemma func_example_11: \forall integer a, b; is_even(a) && is_even(b) && is_positive(a) && is_positive(b) ==> a + b + 6 > a + b;
*/

int main() {
    return 0;
}

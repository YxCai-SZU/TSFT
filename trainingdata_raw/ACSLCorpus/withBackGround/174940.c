/*@
    predicate is_greater_than_10(integer x) = x > 10;
    predicate is_less_than_or_equal_to_10(integer x) = x <= 10;

    logic integer decrement(integer x) = x - 1;
    logic integer double_val(integer x) = x * 2;
    logic integer non_strict_monotonic_decrease(integer x) = x - 1;

    lemma test_decrement:
        decrement(10) == 9 && decrement(0) == -1;

    lemma test_double:
        double_val(5) == 10;

    lemma test_is_greater_than_10:
        is_greater_than_10(15) && !is_greater_than_10(5);

    lemma test_is_less_than_or_equal_to_10:
        is_less_than_or_equal_to_10(10) && !is_less_than_or_equal_to_10(15);

    lemma test_non_strict_monotonic_decrease:
        non_strict_monotonic_decrease(10) <= 10;

    lemma proof_non_strict_monotonic_decrease:
        \forall integer x; x > 0 ==> non_strict_monotonic_decrease(x) <= x;
*/

int main() {
    return 0;
}

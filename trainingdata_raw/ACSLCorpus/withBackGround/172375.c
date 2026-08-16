/*@
predicate is_greater_than_negative(integer x) = x > -1;
predicate is_less_than_positive(integer x) = x < 1;
predicate are_not_equal(integer x, integer y) = x != y;
predicate is_greater_than_or_equal(integer x, integer y) = x >= y;
predicate is_less_than_or_equal(integer x, integer y) = x <= y;
predicate are_both_true(boolean a, boolean b) = a == \true && b == \true;

lemma greater_than_negative: \forall integer x; x > 0 ==> is_greater_than_negative(x);
lemma less_than_positive: \forall integer x; x < 0 ==> is_less_than_positive(x);
lemma not_equal_int: \forall integer x, y; are_not_equal(x, y) ==> are_not_equal(x, y);
lemma greater_than_or_equal: \forall integer x, y; is_greater_than_or_equal(x, y) ==> is_greater_than_or_equal(x, y);
lemma less_than_or_equal: \forall integer x, y; is_less_than_or_equal(x, y) ==> is_less_than_or_equal(x, y);
lemma test_bool: \forall boolean a, b; a && b ==> are_both_true(a, b);
*/

int main() {
    return 0;
}

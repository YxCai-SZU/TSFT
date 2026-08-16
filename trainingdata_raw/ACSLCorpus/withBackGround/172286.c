/*@
predicate less_than_five(integer x) = x < 5;
predicate greater_than_five(integer x) = x > 5;
*/

/*@
lemma test_calc_strict:
  \forall integer x, y;
    less_than_five(x) && less_than_five(y) ==> x + y < 10;
*/

/*@
lemma test_calc_strict_less_than:
  \forall integer x, y;
    less_than_five(x) && less_than_five(y) ==> x + y <= x + y;
*/

/*@
lemma test_calc_strict_greater_than:
  \forall integer x, y;
    greater_than_five(x) && greater_than_five(y) ==> x + y > 10;
*/

int main() {
    return 0;
}

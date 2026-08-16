/*@
predicate test_bool(integer a) = a == 0;
logic integer double_value(integer a) = a * 2;
predicate is_positive(integer a) = a > 0;

lemma calc_example_8:
    \forall integer a; test_bool(a) <==> (a == 0);

lemma calc_example_double_value:
    \forall integer a; a >= 0 ==> double_value(a) == a * 2;

lemma calc_example_is_positive:
    \forall integer a; a > 0 ==> is_positive(a);
*/

int main() {
    //@ assert !test_bool(1);
    //@ assert \forall integer a; a >= 0 ==> double_value(a) == a * 2;
    //@ assert \forall integer a; a > 0 ==> is_positive(a);
    return 0;
}

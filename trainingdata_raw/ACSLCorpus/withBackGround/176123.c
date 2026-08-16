/*@
predicate valid_range(integer a) = 1 <= a && a <= 100;

lemma calc_example_3: \forall integer a; a + 1 <= a + 2 && a + 2 <= a + 3;
lemma calc_example_4: \forall integer a; valid_range(a) ==> a * 2 <= 200;
lemma calc_example_5: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000;
lemma calc_example_6: \forall integer a, b, c; valid_range(a) && valid_range(b) && valid_range(c) ==> a * b * c <= 1000000;
lemma calc_example_7: \forall integer a; valid_range(a) ==> a * 2 + 1 <= 201;
lemma calc_example_8: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * 2 + b <= 301;
*/

int main() {
    return 0;
}

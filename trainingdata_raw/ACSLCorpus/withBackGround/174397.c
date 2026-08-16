/*@
predicate a_lt_b(int a, int b) = a < b;
predicate b_lt_c(int b, int c) = b < c;
predicate a_le_c(int a, int c) = a <= c;
*/
/*@
lemma calc_example_2: \forall integer a, b, c; a < b && b < c ==> a <= c;
*/

/*@
predicate a_gt_b(int a, int b) = a > b;
predicate b_gt_c(int b, int c) = b > c;
predicate a_ge_c(int a, int c) = a >= c;
*/
/*@
lemma calc_example_3: \forall integer a, b, c; a > b && b > c ==> a >= c;
*/

/*@
predicate b_ge_c(int b, int c) = b >= c;
*/
/*@
lemma calc_example_4: \forall integer a, b, c; a > b && b >= c ==> a >= c;
*/

/*@
predicate b_eq_c(int b, int c) = b == c;
predicate a_lt_c(int a, int c) = a < c;
*/
/*@
lemma calc_example_5: \forall integer a, b, c; a < b && b == c ==> a < c;
*/

/*@
predicate a_gt_c(int a, int c) = a > c;
*/
/*@
lemma calc_example_6: \forall integer a, b, c; a > b && b == c ==> a > c;
*/

int main() {
    return 0;
}

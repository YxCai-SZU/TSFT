/*@
    predicate a_gt_b_gt_c(integer a, integer b, integer c) = a > b && b > c;
    predicate a_lt_b_lt_c(integer a, integer b, integer c) = a < b && b < c;
    predicate a_gt_b_gt_c_gt_d(integer a, integer b, integer c, integer d) = a > b && b > c && c > d;
    predicate a_lt_b_lt_c_lt_d(integer a, integer b, integer c, integer d) = a < b && b < c && c < d;
*/

/*@
    lemma calc_example_15: \forall integer a, b, c; a_gt_b_gt_c(a, b, c) ==> a > c;
    lemma calc_example_16: \forall integer a, b, c; a_lt_b_lt_c(a, b, c) ==> a < c;
    lemma calc_example_17: \forall integer a, b, c, d; a_gt_b_gt_c_gt_d(a, b, c, d) ==> a > d;
    lemma calc_example_18: \forall integer a, b, c, d; a_lt_b_lt_c_lt_d(a, b, c, d) ==> a < d;
    lemma complex_calc_example: \forall integer a, b, c; a_gt_b_gt_c(a, b, c) ==> a > c;
    lemma complex_calc_example_2: \forall integer a, b, c; a_lt_b_lt_c(a, b, c) ==> a < c;
*/

int main() {
    return 0;
}

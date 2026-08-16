/*@
predicate a_lt_b(integer a, integer b) = a < b;
predicate b_lt_c(integer b, integer c) = b < c;
predicate c_lt_d(integer c, integer d) = c < d;
predicate a_lt_d(integer a, integer d) = a < d;

lemma calc_example_3: \forall integer a, b, c, d;
    a_lt_b(a, b) && b_lt_c(b, c) && c_lt_d(c, d) ==> a_lt_d(a, d);

predicate x_in_range(integer x) = 2 <= x && x <= 5;
predicate y_in_range(integer y) = 3 <= y && y <= 7;
predicate product_in_range(integer x, integer y) = 5 <= x * y && x * y <= 35;

lemma proof_example_3: \forall integer x, y;
    x_in_range(x) && y_in_range(y) ==> product_in_range(x, y);
*/

void main() {
    //@ assert \true;
}

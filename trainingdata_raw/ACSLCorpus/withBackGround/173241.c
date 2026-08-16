/*@
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate b_le_c(integer b, integer c) = b <= c;
    predicate a_le_c(integer a, integer c) = a <= c;

    lemma calc_multistep_example_1: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);
    lemma calc_multistep_example_3: \forall integer a, b, c; a_le_b(a, b) && b_le_c(b, c) ==> a_le_c(a, c);

    predicate x_in_range(integer x) = 0 <= x && x <= 5;
    predicate y_in_range(integer y) = 0 <= y && y <= 5;
    predicate x_lt_y(integer x, integer y) = x < y;
    predicate diff_le_5(integer x, integer y) = y - x <= 5;

    lemma calc_multistep_example_2: \forall integer x, y; x_in_range(x) && y_in_range(y) && x_lt_y(x, y) ==> diff_le_5(x, y);
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    int a;
    int b;
    int c;
    int x;
    int y;

    //@ ghost int ga = a;
    //@ ghost int gb = b;
    //@ ghost int gc = c;
    //@ ghost int gx = x;
    //@ ghost int gy = y;

    //@ assert a_le_b(ga, gb) && b_le_c(gb, gc) ==> a_le_c(ga, gc);
    //@ assert x_in_range(gx) && y_in_range(gy) && x_lt_y(gx, gy) ==> diff_le_5(gx, gy);
    //@ assert a_le_b(ga, gb) && b_le_c(gb, gc) ==> a_le_c(ga, gc);

    return 0;
}

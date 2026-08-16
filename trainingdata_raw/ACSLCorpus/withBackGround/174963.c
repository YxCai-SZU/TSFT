/*@
    predicate greater_than_three_pre(integer a, integer b) =
        a > 0 && b > 0 && a + b > 3;
    predicate greater_than_three_post(integer a, integer b) =
        a + b > 3;
    lemma greater_than_three_lemma:
        \forall integer a, b; greater_than_three_pre(a, b) ==> greater_than_three_post(a, b);
*/

/*@
    predicate non_linearity_pre(integer x) =
        0 <= x && x <= 10;
    predicate non_linearity_post(integer x) =
        x * x <= 100;
    lemma non_linearity_lemma:
        \forall integer x; non_linearity_pre(x) ==> non_linearity_post(x);
*/

/*@
    predicate non_linearity_2_pre(integer x, integer y) =
        0 <= x && x <= 10 && 0 <= y && y <= 10;
    predicate non_linearity_2_post(integer x, integer y) =
        x * y <= 100;
    lemma non_linearity_2_lemma:
        \forall integer x, y; non_linearity_2_pre(x, y) ==> non_linearity_2_post(x, y);
*/

/*@
    predicate non_linearity_3_pre(integer x, integer y, integer z) =
        0 <= x && x <= 10 && 0 <= y && y <= 10 && 0 <= z && z <= 10;
    predicate non_linearity_3_post(integer x, integer y, integer z) =
        x * y * z <= 1000;
    lemma non_linearity_3_lemma:
        \forall integer x, y, z; non_linearity_3_pre(x, y, z) ==> non_linearity_3_post(x, y, z);
*/

/*@
    predicate is_square_odd_pre(integer x) =
        x >= 0 && x <= 1;
    predicate is_square_odd_post(integer x) =
        x == 0 || x == 1;
    lemma is_square_odd_lemma:
        \forall integer x; is_square_odd_pre(x) ==> is_square_odd_post(x);
*/

int main() {
    return 0;
}

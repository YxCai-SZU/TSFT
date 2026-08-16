/*@
    predicate non_negative(integer n) = n >= 0;
    predicate leq(integer a, integer b) = a <= b;

    lemma double_incr:
        \forall integer num; non_negative(num) ==> num + num == 2 * num;

    lemma calc_example_3:
        \forall integer x, y; leq(x, y) ==> x + y <= y + y;

    lemma lemma_x_y_num:
        \forall integer x, y, num; leq(x, y) && non_negative(num) ==> x + y + num <= y + y + num;

    lemma lemma_x_y_num_2:
        \forall integer x, y, num; leq(x, y) && non_negative(num) ==> x + y + 2 * num <= y + y + 2 * num;

    lemma lemma_x_y_num_3:
        \forall integer x, y, num; leq(x, y) && non_negative(num) ==> x + y + 3 * num <= y + y + 3 * num;

    lemma lemma_x_y_num_4:
        \forall integer x, y, num; leq(x, y) && non_negative(num) ==> x + y + 4 * num <= y + y + 4 * num;

    lemma lemma_x_y_num_5:
        \forall integer x, y, num; leq(x, y) && non_negative(num) ==> x + y + 5 * num <= y + y + 5 * num;
*/

int main() {
    int x;
    int y;
    int num;
    
    //@ assert non_negative(num) && leq(x, y) ==> x + y + 5 * num <= y + y + 5 * num;
    
    return 0;
}

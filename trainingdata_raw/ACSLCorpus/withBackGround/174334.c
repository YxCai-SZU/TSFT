/*@
predicate le_int(integer a, integer b) = a <= b;
predicate eq_int(integer a, integer b) = a == b;
predicate ge_int(integer a, integer b) = a >= b;

lemma example_1: \forall integer x, y; le_int(x, y) && le_int(y, 5) ==> le_int(x, 5);
lemma example_2: \forall integer x, y; eq_int(x, y - 2) && le_int(y, 5) ==> le_int(x, 5);
lemma example_3: \forall integer x, y; eq_int(x, y - 2) && le_int(y, 5) && ge_int(x, 0) ==> ge_int(y, 0);
*/

/*@
requires x <= y && y <= 5;
ensures x <= 5;
assigns \nothing;
*/
void example_1_c(int x, int y) {
    //@ assert x <= 5;
}

/*@
requires x == y - 2 && y <= 5;
ensures x <= 5;
assigns \nothing;
*/
void example_2_c(int x, int y) {
    //@ assert x <= 5;
}

/*@
requires x == y - 2 && y <= 5 && 0 <= x;
ensures 0 <= y;
assigns \nothing;
*/
void example_3_c(int x, int y) {
    //@ assert 0 <= y;
}

int main() {
    return 0;
}

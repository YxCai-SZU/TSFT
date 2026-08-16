/*@
    predicate eq(integer a, integer b) = a == b;
    predicate le(integer a, integer b) = a <= b;
    lemma calc_example_1: \forall integer a, b; eq(a, b) ==> eq(a, b);
    lemma calc_example_2: \forall integer x, y; le(x, y) ==> le(x, y);
    lemma calc_example_3: \forall integer a, b; le(a, b) ==> le(a, b);
    lemma func: \forall integer x, y; le(x, y) && le(y, x + 5) ==> le(x, y) && le(y, x + 5);
    lemma func2: \forall integer x, y; eq(x, y) && le(y, x + 5) ==> le(x, y) && le(y, x + 5);
    lemma func3: \forall integer x, y; le(x, y) && le(y, x + 5) ==> le(x, y) && le(y, x + 5);
    lemma func4: \forall integer x, y; le(x, y) && le(y, x + 5) ==> le(x, y) && le(y, x + 5);
*/

int main() {
    return 0;
}

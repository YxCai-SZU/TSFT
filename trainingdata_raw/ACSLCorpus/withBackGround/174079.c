/*@
    predicate nonnegative(integer x) = x >= 0;

    lemma triple_incr:
        \forall integer num; nonnegative(num) ==> num + num + num == 3 * num;

    lemma calc_example_5:
        \forall integer x, y; x <= y ==> x + y <= y + y;

    lemma square_incr:
        \forall integer x; nonnegative(x) ==> x * x == x * x;

    lemma neg_square_incr:
        \forall integer x; nonnegative(x) ==> -(x * x) == -(x * x);

    lemma abs_square_incr:
        \forall integer x; nonnegative(x) ==> 
            (x >= 0 ? x * x : -(x * x)) == (x >= 0 ? x * x : -(x * x));

    lemma abs_square_decr:
        \forall integer x; nonnegative(x) ==> 
            (x >= 0 ? -(x * x) : x * x) == (x >= 0 ? -(x * x) : x * x);

    lemma square_decr:
        \forall integer x; nonnegative(x) ==> -(x * x) == -(x * x);
*/

int main() {
    return 0;
}

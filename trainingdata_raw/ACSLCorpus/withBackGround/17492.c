/*@
    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;

    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;

    lemma calc_example_11:
        \forall integer a, b, c;
            a <= b && b <= c ==> a <= c;

    lemma is_strictly_decreasing_sequence:
        \forall integer a, b, c;
            strictly_decreasing(a, b, c) ==> a > c;

    lemma is_strictly_increasing_sequence:
        \forall integer a, b, c;
            strictly_increasing(a, b, c) ==> a < c;

    lemma func_example_11:
        \forall integer a, b, c;
            strictly_increasing(a, b, c) ==> a < c;

    lemma func_example_12:
        \forall integer a, b, c;
            strictly_decreasing(a, b, c) ==> a > c;

    lemma func_example_13:
        \forall integer a, b, c;
            a == b && b == c ==> a == c;

    lemma func_example_14:
        \forall integer a, b, c;
            a <= b && b <= c ==> a <= c;

    lemma func_example_15:
        \forall integer a, b, c;
            a >= b && b >= c ==> a >= c;
*/

int main() {
    //@ assert \true;
    return 0;
}

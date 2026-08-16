/*@
    predicate transitive_condition(integer a, integer b, integer c) =
        a <= b && b <= c;

    predicate strictly_increasing_condition(integer a, integer b, integer c) =
        a < b && b < c;

    predicate strictly_decreasing_condition(integer a, integer b, integer c) =
        a > b && b > c;

    predicate strictly_non_decreasing_condition(integer a, integer b, integer c) =
        a >= b && b >= c;

    predicate fibonacci_condition(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0 && c == a + b;

    lemma assert_transitive:
        \forall integer a, b, c;
            transitive_condition(a, b, c) ==> a <= c;

    lemma assert_strictly_increasing:
        \forall integer a, b, c;
            strictly_increasing_condition(a, b, c) ==> a < c;

    lemma assert_strictly_decreasing:
        \forall integer a, b, c;
            strictly_decreasing_condition(a, b, c) ==> a > c;

    lemma assert_strictly_non_decreasing:
        \forall integer a, b, c;
            strictly_non_decreasing_condition(a, b, c) ==> a >= c;

    lemma assert_fibonacci:
        \forall integer a, b, c;
            fibonacci_condition(a, b, c) ==> a <= c && b <= c;

    logic integer calc_example_2(integer x) = 3 * (x + 2);
    logic integer calc_example_2_bound(integer x) = 3 * x + 20;

    lemma calc_example_2_proof:
        \forall integer x;
            x >= 0 ==> calc_example_2(x) <= calc_example_2_bound(x);

    logic integer calc_example_3(integer x) = 2 * (x + 2);
    logic integer calc_example_3_bound(integer x) = 2 * x + 20;

    lemma calc_example_3_proof:
        \forall integer x;
            x >= 0 ==> calc_example_3(x) <= calc_example_3_bound(x);
*/

void main(void)
{
    int a;
    int b;
    int c;
    int x;

    //@ assert transitive_condition(1, 2, 3);
    //@ assert strictly_increasing_condition(1, 2, 3);
    //@ assert strictly_decreasing_condition(3, 2, 1);
    //@ assert strictly_non_decreasing_condition(3, 2, 2);
    //@ assert fibonacci_condition(1, 2, 3);
    //@ assert calc_example_2(5) <= calc_example_2_bound(5);
    //@ assert calc_example_3(5) <= calc_example_3_bound(5);
}

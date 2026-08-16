/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer count_matches(integer a, integer b, integer c) =
        (a == b ? 1 : 0) +
        (b == c ? 1 : 0) +
        (a == c ? 1 : 0);

    lemma count_range:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            0 <= count_matches(a, b, c) <= 3;

    lemma all_equal_implies_three:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (a == b && b == c) ==> count_matches(a, b, c) == 3;

    lemma any_equal_implies_at_least_one:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (a == b || b == c || a == c) ==> count_matches(a, b, c) >= 1;

    lemma all_different_implies_zero:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            (a != b && b != c && a != c) ==> count_matches(a, b, c) == 0;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && b == c) ==> \result == 3;
    ensures (a == b || b == c || a == c) ==> \result >= 1;
    ensures (a != b && b != c && a != c) ==> \result == 0;
    ensures 0 <= \result <= 3;
*/
int func(int a, int b, int c)
{
    int count = 0;

    //@ assert in_range(a) && in_range(b) && in_range(c);

    if (a == b) {
        count += 1;
        //@ assert count == 1;
    }

    if (b == c) {
        count += 1;
        //@ assert count <= 2;
    }

    if (a == c) {
        count += 1;
        //@ assert count <= 3;
    }

    //@ assert count == 0 || count == 1 || count == 2 || count == 3;
    return count;
}

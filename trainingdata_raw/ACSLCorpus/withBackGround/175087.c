/*@
    predicate is_arithmetic_sequence(integer a, integer b, integer c) =
        b - a == c - b;
*/

/*@
    lemma arithmetic_sequence_implies:
        \forall integer a, b, c;
            1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==>
            (b - a == c - b ==> (b - a == c - b));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int result;
    //@ assert is_arithmetic_sequence(a, b, c) ==> (b - a == c - b);
    result = (b - a == c - b);
    return result;
}

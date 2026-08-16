/*@
    predicate are_equal(integer a, integer b, integer c) =
        a == b && b == c;

    predicate a_eq_b(integer a, integer b, integer c) =
        a == b && b != c;

    predicate b_eq_c(integer a, integer b, integer c) =
        b == c && a != b;

    predicate c_eq_a(integer a, integer b, integer c) =
        c == a && b != c;

    predicate all_different(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    lemma all_equal_implies_a_eq_b:
        \forall integer a, b, c; are_equal(a, b, c) ==> a == b && b == c;

    lemma a_eq_b_implies_condition:
        \forall integer a, b, c; a_eq_b(a, b, c) ==> a == b && b != c;

    lemma b_eq_c_implies_condition:
        \forall integer a, b, c; b_eq_c(a, b, c) ==> b == c && a != b;

    lemma c_eq_a_implies_condition:
        \forall integer a, b, c; c_eq_a(a, b, c) ==> c == a && b != c;

    lemma all_different_implies_condition:
        \forall integer a, b, c; all_different(a, b, c) ==> a != b && b != c && a != c;
*/

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures (A == B && B != C) ==> \result == C;
    ensures (B == C && A != B) ==> \result == A;
    ensures (C == A && B != C) ==> \result == B;
    ensures (A != B && B != C && A != C) ==> \result == 0;
*/
int func(int A, int B, int C)
{
    int result;

    if (A == B && B == C)
    {
        //@ assert are_equal(A, B, C);
        result = 0;
    }
    else if (A == B && B != C)
    {
        //@ assert a_eq_b(A, B, C);
        result = C;
    }
    else if (B == C && A != B)
    {
        //@ assert b_eq_c(A, B, C);
        result = A;
    }
    else if (C == A && B != C)
    {
        //@ assert c_eq_a(A, B, C);
        result = B;
    }
    else
    {
        //@ assert all_different(A, B, C);
        result = 0;
    }

    return result;
}

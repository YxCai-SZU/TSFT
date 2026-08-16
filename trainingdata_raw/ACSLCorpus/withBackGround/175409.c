/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate result_valid(integer a, integer b, integer c, integer d, integer r) =
        r == a + c || r == a + d || r == b + c || r == b + d;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    ensures result_valid(A, B, C, D, \result);
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int min_AB;
    int min_CD;
    int result;

    //@ assert in_range(A) && in_range(B);
    if (A < B) {
        min_AB = A;
    } else {
        min_AB = B;
    }
    //@ assert in_range(min_AB);

    //@ assert in_range(C) && in_range(D);
    if (C < D) {
        min_CD = C;
    } else {
        min_CD = D;
    }
    //@ assert in_range(min_CD);

    //@ assert -200 <= min_AB + min_CD <= 200;
    result = min_AB + min_CD;
    //@ assert result_valid(A, B, C, D, result);
    return result;
}

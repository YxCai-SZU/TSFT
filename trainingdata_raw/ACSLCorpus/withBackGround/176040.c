/*@
    predicate valid_input(integer A, integer B) =
        1 <= A && A <= 3 &&
        1 <= B && B <= 3 &&
        A != B;

    logic integer compute_result(integer A, integer B) =
        6 - A - B;
*/

/*@
    requires valid_input(A, B);
    ensures \result == compute_result(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    //@ assert valid_input(A, B);
    int result = 6 - A - B;
    //@ assert result == compute_result(A, B);
    return result;
}

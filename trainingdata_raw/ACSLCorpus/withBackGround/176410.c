/*@
    predicate valid_input(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100;

    logic integer compute_result(integer A, integer B) =
        A - (B * 2);

    predicate result_spec(integer result, integer A, integer B) =
        result >= 0 &&
        (result == compute_result(A, B) || result == 0);
*/

/*@
    requires valid_input(A, B);
    ensures result_spec(\result, A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    //@ assert valid_input(A, B);
    result = A - (B * 2);
    //@ assert result == compute_result(A, B);
    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
        //@ assert result_spec(result, A, B);
        return result;
    }
    else
    {
        //@ assert result >= 0;
        //@ assert result_spec(result, A, B);
        return result;
    }
}

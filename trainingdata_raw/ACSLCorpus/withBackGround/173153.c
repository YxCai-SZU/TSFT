/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100 &&
        1 <= C && C <= 100;

    predicate result_range(integer r) =
        r >= 1 && r <= 3;
*/

/*@
    requires valid_input(A, B, C);
    ensures result_range(\result);
    assigns \nothing;
*/
int func(unsigned int A, unsigned int B, unsigned int C)
{
    int result = -1;
    unsigned int total_items;
    unsigned int left_out;

    total_items = A + B + C;

    if (A >= 1 && B >= 1 && C >= 1)
    {
        //@ assert total_items >= 3;
        left_out = total_items - 3;

        if (left_out == 0 || left_out == 3)
        {
            result = 3;
        }
        else
        {
            result = 2;
        }
    }
    else if (A >= 1 || B >= 1 || C >= 1)
    {
        result = 1;
    }

    //@ assert result >= 1;
    //@ assert result <= 3;
    return result;
}

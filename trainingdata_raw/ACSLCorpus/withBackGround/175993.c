#include <stdbool.h>

/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= B && B <= A && A <= 20 &&
        1 <= C && C <= 20;

    logic integer compute_result(integer A, integer B, integer C) =
        C > (A - B) ? C - (A - B) : 0;

    lemma result_properties:
        \forall integer A, B, C;
        valid_input(A, B, C) ==>
        compute_result(A, B, C) >= 0 &&
        compute_result(A, B, C) <= C &&
        (compute_result(A, B, C) == C - (A - B) ||
         compute_result(A, B, C) == 0);
*/

/*@
    requires valid_input(A, B, C);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int result;
    int temp;

    //@ assert valid_input(A, B, C);
    
    temp = A - B;
    
    if (C > temp)
    {
        //@ assert C - temp >= 0;
        result = C - temp;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= C;
    //@ assert result == C - (A - B) || result == 0;
    
    return result;
}

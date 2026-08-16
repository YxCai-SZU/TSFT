#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= B && B <= A && A <= 20 &&
        1 <= C && C <= 20;

    logic integer compute_answer(integer A, integer B, integer C) =
        C - (A - B);

    lemma answer_bounds: \forall integer A, B, C;
        valid_input(A, B, C) ==> 
        compute_answer(A, B, C) <= C && compute_answer(A, B, C) >= -19;

    lemma answer_property: \forall integer A, B, C, integer result;
        valid_input(A, B, C) && result >= 0 && result <= C &&
        (result == compute_answer(A, B, C) || result == 0) ==>
        result == C - (A - B) || result == 0;
*/

/*@
    requires valid_input(A, B, C);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    int32_t answer;
    //@ assert C >= 0;
    //@ assert A - B >= 0;
    //@ assert C - (A - B) <= C;
    
    answer = C - (A - B);
    
    if (answer > 0)
    {
        //@ assert answer == C - (A - B);
        //@ assert answer >= 0;
        //@ assert answer <= C;
        return answer;
    }
    else
    {
        //@ assert answer <= 0;
        //@ assert 0 >= 0;
        //@ assert 0 <= C;
        return 0;
    }
}

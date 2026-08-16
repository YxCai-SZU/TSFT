#include <stdbool.h>

/*@ predicate condition_holds(integer A, integer B, integer C) =
      A - B >= C;
*/

/*@ logic integer compute_result(integer A, integer B, integer C) =
      C - (A - B);
*/

/*@ lemma result_range: \forall integer A, B, C;
      1 <= B && B <= A && A <= 20 && 1 <= C && C <= 20 ==>
      compute_result(A, B, C) <= C;
*/

/*@ lemma zero_result_lemma: \forall integer A, B, C;
      1 <= B && B <= A && A <= 20 && 1 <= C && C <= 20 &&
      condition_holds(A, B, C) ==>
      compute_result(A, B, C) <= 0;
*/

/*@ requires 1 <= B && B <= A && A <= 20 && 1 <= C && C <= 20;
    ensures \result >= 0 && \result <= C;
    ensures condition_holds(A, B, C) ==> \result == 0;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int result;
    
    //@ assert 1 <= B && B <= A && A <= 20 && 1 <= C && C <= 20;
    
    result = C - (A - B);
    
    if (result < 0) {
        result = 0;
    } else {
        //@ assert result <= C;
    }
    
    //@ assert result >= 0 && result <= C;
    //@ assert condition_holds(A, B, C) ==> result == 0;
    
    return result;
}

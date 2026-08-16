#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        (a == b || b == c || c == a) ? 2 : 3;

    lemma result_range: \forall integer a,b,c;
        is_valid_params(a,b,c) ==> 1 <= func_result(a,b,c) <= 3;

    lemma case_1: \forall integer a,b,c;
        is_valid_params(a,b,c) && a == b && b == c ==> func_result(a,b,c) == 1;

    lemma case_2: \forall integer a,b,c;
        is_valid_params(a,b,c) && (a == b && b != c) || (b == c && c != a) || (c == a && a != b) 
        ==> func_result(a,b,c) == 2;

    lemma case_3: \forall integer a,b,c;
        is_valid_params(a,b,c) && a != b && b != c && c != a ==> func_result(a,b,c) == 3;
*/

/*@
    requires is_valid_params(A, B, C);
    ensures \result == func_result(A, B, C);
    ensures 1 <= \result <= 3;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    int32_t result;
    
    //@ assert is_valid_params(A, B, C);
    
    if (A == B && B == C)
    {
        //@ assert A == B && B == C;
        result = 1;
    }
    else if (A == B || B == C || C == A)
    {
        //@ assert (A == B && B != C) || (B == C && C != A) || (C == A && A != B);
        result = 2;
    }
    else
    {
        //@ assert A != B && B != C && C != A;
        result = 3;
    }
    
    //@ assert result == func_result(A, B, C);
    return result;
}

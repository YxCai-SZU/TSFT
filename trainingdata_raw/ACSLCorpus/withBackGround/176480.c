#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer func_result(integer A, integer B, integer C) =
        (A == B && B == C) ? 1 :
        (A == B || B == C || C == A) ? 2 : 3;

    lemma result_range: \forall integer A, B, C;
        valid_range(A) && valid_range(B) && valid_range(C) ==>
        1 <= func_result(A, B, C) <= 3;

    lemma result_case1: \forall integer A, B, C;
        valid_range(A) && valid_range(B) && valid_range(C) ==>
        (func_result(A, B, C) == 1 ==> (A == B && B == C));

    lemma result_case2: \forall integer A, B, C;
        valid_range(A) && valid_range(B) && valid_range(C) ==>
        (func_result(A, B, C) == 2 ==> 
            ((A == B && A != C) || (A == C && A != B) || (B == C && B != A)));

    lemma result_case3: \forall integer A, B, C;
        valid_range(A) && valid_range(B) && valid_range(C) ==>
        (func_result(A, B, C) == 3 ==> (A != B && B != C && A != C));
*/

/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (A == B && B == C);
    ensures \result == 2 ==> ((A == B && A != C) || (A == C && A != B) || (B == C && B != A));
    ensures \result == 3 ==> (A != B && B != C && A != C);
*/
int func(int A, int B, int C)
{
    int ans;

    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);

    if (A == B && B == C)
    {
        ans = 1;
    }
    else if (A == B || B == C || C == A)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }

    //@ assert ans >= 1 && ans <= 3;
    //@ assert ans == 1 ==> (A == B && B == C);
    //@ assert ans == 2 ==> ((A == B && A != C) || (A == C && A != B) || (B == C && B != A));
    //@ assert ans == 3 ==> (A != B && B != C && A != C);

    return ans;
}

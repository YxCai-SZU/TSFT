#include <stdbool.h>

/*@
    predicate is_one(integer A, integer B, integer C, integer ans) =
        ans == 1 ==> (A == B && B == C);
    predicate is_two(integer A, integer B, integer C, integer ans) =
        ans == 2 ==> ((A == B && B != C) || (A == C && C != B) || (B == C && A != C));
    predicate is_three(integer A, integer B, integer C, integer ans) =
        ans == 3 ==> (A != B && B != C && A != C);
    predicate ans_range(integer ans) = 1 <= ans && ans <= 3;
*/

/*@
    requires -100 <= A && A <= 100;
    requires -100 <= B && B <= 100;
    requires -100 <= C && C <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures is_one(A, B, C, \result);
    ensures is_two(A, B, C, \result);
    ensures is_three(A, B, C, \result);
*/
int func(int A, int B, int C)
{
    int ans;
    //@ assert -100 <= A && A <= 100;
    //@ assert -100 <= B && B <= 100;
    //@ assert -100 <= C && C <= 100;
    
    if (A == B && B == C) {
        ans = 1;
        //@ assert is_one(A, B, C, ans);
    } else if (A == B || B == C || C == A) {
        ans = 2;
        //@ assert is_two(A, B, C, ans);
    } else {
        ans = 3;
        //@ assert is_three(A, B, C, ans);
    }
    
    //@ assert ans_range(ans);
    return ans;
}

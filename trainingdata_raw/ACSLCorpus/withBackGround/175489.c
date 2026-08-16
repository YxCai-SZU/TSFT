#include <stdint.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer func_res(integer A, integer B, integer C) =
        (A <= B && C <= B) ? 1 : 0;

    lemma func_correct:
        \forall integer A, B, C;
        in_range(A) && in_range(B) && in_range(C) ==>
        (func_res(A, B, C) == 1 && A <= B && C <= B) ||
        (func_res(A, B, C) == 0 && (A > B || C > B));
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures \result == func_res(A, B, C);
    ensures (\result == 1 && A <= B && C <= B) ||
             (\result == 0 && (A > B || C > B));
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;
    //@ assert in_range(A) && in_range(B) && in_range(C);
    
    if (A <= B && C <= B)
    {
        ans = 1;
        //@ assert ans == 1 && A <= B && C <= B;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0 && (A > B || C > B);
    }
    
    //@ assert ans == func_res(A, B, C);
    return ans;
}

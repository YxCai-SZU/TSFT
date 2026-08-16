/*@
    predicate in_range(integer x) = -100 <= x <= 100;
    
    logic integer func_spec(integer A, integer B, integer C) =
        (A == B && A != C) ? C :
        (A != B && A == C) ? B :
        (A == C && A != B) ? B :
        (A == B && A == C) ? A :
        (A != B && B == C) ? A : A;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures \result == func_spec(A, B, C);
    ensures in_range(\result);
*/
long func(long A, long B, long C)
{
    long ans;
    //@ assert in_range(A) && in_range(B) && in_range(C);
    
    if (A == B) {
        ans = C;
        //@ assert A == B && ans == C;
    } else if (A == C) {
        ans = B;
        //@ assert A != B && A == C && ans == B;
    } else {
        ans = A;
        //@ assert A != B && A != C && ans == A;
    }
    
    //@ assert in_range(ans);
    return ans;
}

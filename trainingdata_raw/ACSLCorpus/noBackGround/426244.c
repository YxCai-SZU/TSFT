/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (A == B && B == C);
    ensures \result == 2 ==> (A == B || A == C || B == C);
    ensures \result == 3 ==> (A != B && B != C && A != C);
*/
int func(int A, int B, int C)
{
    int result;
    
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    
    if (A == B && B == C) {
        result = 1;
    } else if (A != B && B != C && A != C) {
        result = 3;
    } else {
        result = 2;
    }
    
    //@ assert result >= 1 && result <= 3;
    //@ assert result == 1 ==> (A == B && B == C);
    //@ assert result == 2 ==> (A == B || A == C || B == C);
    //@ assert result == 3 ==> (A != B && B != C && A != C);
    
    return result;
}

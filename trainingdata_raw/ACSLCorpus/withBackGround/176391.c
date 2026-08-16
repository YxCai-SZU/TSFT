/*@
    predicate is_between(integer A, integer B, integer C) =
        (A < C && C < B) || (A > C && C > B);
*/

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == 1 <==> is_between(A, B, C);
*/
int func(int A, int B, int C) {
    int state = 0;
    
    //@ ghost int old_A = A, old_B = B, old_C = C;
    
    if (A == C) {
        state = 1;
    }
    
    if (C == B) {
        state = 2;
    }
    
    if ((A < C && C < B) || (A > C && C > B)) {
        state = 3;
    }
    
    //@ assert state == 3 <==> is_between(old_A, old_B, old_C);
    
    return state == 3;
}

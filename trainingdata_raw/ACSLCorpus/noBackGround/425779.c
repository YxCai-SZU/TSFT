/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int result;
    
    //@ assert 1 <= B && B <= A && A <= 20;
    //@ assert 1 <= C && C <= 20;
    
    if (C > (A - B))
    {
        //@ assert C - (A - B) >= 0 && C - (A - B) <= C;
        result = C - (A - B);
    }
    else
    {
        //@ assert 0 >= 0 && 0 <= C;
        result = 0;
    }
    
    return result;
}

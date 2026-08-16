/*@
    requires 0 <= A <= 100 && 0 <= B <= 100 && 0 <= C <= 100;
    ensures \result >= 0 && \result <= A + B + C;
    assigns \nothing;
*/
int min_tasty_cookies(int A, int B, int C)
{
    int ans;
    //@ ghost int A_spec = A, B_spec = B, C_spec = C;
    
    if (C > A + B)
    {
        ans = A + B + 1 + B;
    }
    else if (C == A + B)
    {
        ans = B + A;
    }
    else
    {
        ans = C + B;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= A_spec + B_spec + C_spec;
    
    return ans;
}

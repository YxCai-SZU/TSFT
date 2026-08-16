/*@
    requires (1 <= (A) && (A) <= 20) && (1 <= (B) && (B) <= 20) && (1 <= (T) && (T) <= 20);
    ensures \result == (((T) / (A)) * (B));
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B, unsigned int T)
{
    unsigned int ans;
    
    //@ assert A >= 1 && A <= 20;
    //@ assert B >= 1 && B <= 20;
    //@ assert T >= 1 && T <= 20;
    
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    ans = T / A * B;
    return ans;
}

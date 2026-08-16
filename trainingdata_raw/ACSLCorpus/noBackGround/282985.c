/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20) && (1 <= (T) <= 20);
    ensures \result == (T / A) * B;
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B, unsigned int T)
{
    // Variable declarations at scope top
    unsigned int ans;

    //@ assert (1 <= (A) <= 20);
    //@ assert (1 <= (B) <= 20);
    //@ assert (1 <= (T) <= 20);
    
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    ans = (T / A) * B;
    return ans;
}

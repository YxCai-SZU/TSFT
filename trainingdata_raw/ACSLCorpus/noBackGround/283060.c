/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result == ((A) * (B));
    assigns \nothing;
*/
int func(int A, int B)
{
    //@ assert (1 <= (A) <= 100 && 1 <= (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;
    
    int ans;
    ans = A * B;
    
    return ans;
}

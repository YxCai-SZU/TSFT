/*@
    requires (0 <= (n) && (n) <= 0xffff);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int ans;
    
    //@ assert n <= 0xffff;
    //@ assert n * n <= 0xffff * 0xffff;
    
    ans = n * n;
    
    return ans;
}

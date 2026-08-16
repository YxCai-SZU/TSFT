/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int ans;
    
    //@ assert n - k + 1 <= n;
    //@ assert n - k + 1 >= 1;
    
    ans = n - k + 1;
    return ans;
}

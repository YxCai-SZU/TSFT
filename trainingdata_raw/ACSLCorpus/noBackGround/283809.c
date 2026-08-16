/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    ensures ((\result) == ((500 * ((k))) >= (x)));
    assigns \nothing;
*/
int func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100000);
    
    ans = (500 * k) >= x;
    
    //@ assert (500 * (k)) == 500 * k;
    //@ assert ((ans) == ((500 * ((k))) >= (x)));
    
    return ans;
}

int main(void)
{
    // Variable declarations at top of scope
    unsigned int k;
    unsigned int x;
    int result;
    
    return 0;
}

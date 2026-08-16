/*@
    requires (0 <= (n) && (n) < 10);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    // Variable declarations at top
    unsigned int res;
    
    //@ assert 0 <= n && n < 10;
    //@ assert n * n < 10000;
    //@ assert n * n * n < 10000;
    
    res = n * n * n;
    
    //@ assert res == ((n) * (n) * (n));
    return res;
}

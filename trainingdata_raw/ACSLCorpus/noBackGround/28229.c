/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    // Variable declarations at top
    unsigned int res;
    
    //@ assert (1 <= (k) <= (n) <= 50);
    
    res = n - k + 1;
    
    //@ assert res == ((n) - (k) + 1);
    return res;
}

/*@
    requires (1 <= (n) <= 50);
    ensures \result == ((n));
    assigns \nothing;
*/
unsigned int func2(unsigned int n)
{
    // Variable declarations at top
    unsigned int res;
    
    //@ assert (1 <= (n) <= 50);
    
    res = n;
    
    //@ assert res == ((n));
    return res;
}

int main(void)
{
    return 0;
}

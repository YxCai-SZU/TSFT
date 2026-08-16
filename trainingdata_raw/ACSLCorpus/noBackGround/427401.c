/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int result;
    
    //@ assert 1 <= n && n <= 50;
    //@ assert 1 <= k && k <= 50;
    //@ assert n - k + 1 <= 50;
    
    result = n - k + 1;
    return result;
}

int main()
{
    return 0;
}

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n)) - m;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= ((n) * (n));
    
    //@ assert 0 <= ((n) * (n));
    //@ assert ((n) * (n)) <= 10000;
    
    result = n * n - m;
    return result;
}

int main()
{
    return 0;
}

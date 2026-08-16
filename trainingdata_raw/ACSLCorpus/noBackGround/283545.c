/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
long func(long n)
{
    long res;
    
    //@ assert n >= 1 && n <= 9;
    
    //@ assert n * n >= 1 && n * n <= 81;
    
    //@ assert n * n * n >= 1 && n * n * n <= 729;
    
    res = n * n * n;
    
    //@ assert res == ((n) * (n) * (n));
    
    return res;
}

int main()
{
    return 0;
}

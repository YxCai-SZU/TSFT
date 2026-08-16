/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    ensures \result >= 0;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert n * n >= m;
    //@ assert n * n - m >= 0;
    //@ assert 1 <= n * n && n * n <= 10000;
    
    result = n * n - m;
    
    //@ assert result == ((n) * (n) - (m));
    //@ assert result >= 0;
    
    return result;
}

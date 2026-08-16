/*@
    requires 1 <= n && n <= 20 && 1 <= m && m <= 20;
    ensures \result <= m && \result >= (m >= n ? n : m);
*/
int func(unsigned int n, unsigned int m)
{
    unsigned int result;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    
    if (m < n) {
        result = m;
        //@ assert result == m;
    } else {
        result = n;
        //@ assert result == n;
    }
    
    //@ assert ((result) == ((n) < (m) ? (n) : (m)));
    //@ assert result <= m;
    //@ assert result >= (m >= n ? n : m);
    
    return result;
}

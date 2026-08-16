/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == n*n*n;
    ensures 1 <= \result && \result <= 729;
*/
int func(int n)
{
    //@ assert (1 <= (n) && (n) <= 9);
    
    int result;
    
    //@ assert 1 <= n*n && n*n <= 81;
    //@ assert 1 <= n*n*n && n*n*n <= 729;
    
    result = n * n * n;
    
    //@ assert result == n*n*n;
    return result;
}

int main()
{
    return 0;
}

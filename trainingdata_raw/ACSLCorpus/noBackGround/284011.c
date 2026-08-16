/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (((n) + 1) / 2);
    ensures \result >= 1 && \result <= 10000;
*/
int func(int n)
{
    // Variable declarations at scope top
    int ans;
    int result;
    int count;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 10000;
    
    // Arithmetic safety proofs
    //@ assert n + 1 <= 10001;
    //@ assert n / 2 <= 5000;
    
    ans = n + 2 - 1;
    result = 0;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant ans >= 0;
        loop invariant count >= 0;
        loop invariant ans == n + 2 - 1 - 2 * count;
        loop invariant count <= (((n) + 1) / 2);
        loop invariant ans <= n + 2 - 1;
        loop invariant count <= 5000;
        loop assigns ans, count;
        loop variant ans;
    */
    while (ans >= 2)
    {
        ans -= 2;
        count += 1;
    }
    
    result = count;
    
    // Postcondition verification
    //@ assert result == (((n) + 1) / 2);
    
    return result;
}

int main()
{
    return 0;
}

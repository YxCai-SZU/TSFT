/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == n - k + 1;
*/
int func(int n, int k)
{
    int result = 0;
    int i = 0;
    
    //@ ghost int old_k = k;
    //@ ghost int old_n = n;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant result == i;
        loop assigns i, result;
    */
    while (i < k)
    {
        result += 1;
        i += 1;
    }
    
    //@ assert result == k;
    
    return n - result + 1;
}

int main()
{
    return 0;
}

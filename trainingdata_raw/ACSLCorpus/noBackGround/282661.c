/*@
    requires (1 <= (n) <= 100);
    ensures \result >= 3 * n;
    ensures \result <= 4 * n;
*/
int func(int n)
{
    int ans;
    int temp_n;
    int count;
    
    ans = n * 3;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n/2;
        loop invariant temp_n == n - 2 * count;
        loop invariant ans == n * 3;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }
    
    ans += count;
    
    //@ assert ans >= 3 * n;
    //@ assert ans <= 4 * n;
    
    return ans;
}

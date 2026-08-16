/*@
    requires (1 <= (n) <= 100000);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) / 100 * 100);
*/
int func(int n)
{
    int ans;
    int temp_n;
    int count;
    
    ans = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant temp_n >= 0;
        loop invariant count >= 0;
        loop invariant temp_n == n - 100 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 100)
    {
        //@ assert temp_n >= 100;
        temp_n -= 100;
        count += 1;
    }
    
    ans = count * 100;
    //@ assert ans == ((n) / 100 * 100);
    return ans;
}

int main()
{
    return 0;
}

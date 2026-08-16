/*@
    requires 1 <= n <= 100;
    ensures \result == 800 * n - 200 * (n / 15);
*/
int func(int n)
{
    int result;
    int count;
    int i;
    int temp_n;
    int sub;
    
    result = 800 * n;
    count = 0;
    i = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n == n - 15 * count;
        loop invariant 1 <= n <= 100;
        loop assigns temp_n, count;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        count += 1;
    }
    
    sub = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= count;
        loop invariant 0 <= sub <= 200 * count;
        loop invariant sub == 200 * i;
        loop invariant count <= n / 15;
        loop invariant 1 <= n <= 100;
        loop assigns sub, i;
    */
    while (i < count)
    {
        sub += 200;
        i += 1;
    }
    
    result -= sub;
    
    return result;
}

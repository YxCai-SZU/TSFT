/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int i;
    int temp_n;
    
    result = n * 800;
    i = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= i <= n / 15;
        loop invariant temp_n == n - 15 * i;
        loop invariant result == n * 800;
        loop assigns i, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        i += 1;
    }
    
    result -= i * 200;
    
    //@ assert result == n * 800 - (n / 15) * 200;
    
    return result;
}

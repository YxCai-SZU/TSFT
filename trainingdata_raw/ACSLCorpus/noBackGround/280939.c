/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int count;
    int temp_n;
    int i;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    i = 1;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 15 * (i - 1);
        loop invariant 1 <= i <= n / 15 + 1;
        loop assigns temp_n, i;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        i += 1;
    }
    
    count = i - 1;
    
    //@ assert count == n / 15;
    result -= count * 200;
    
    //@ assert result == n * 800 - (n / 15) * 200;
    return result;
}

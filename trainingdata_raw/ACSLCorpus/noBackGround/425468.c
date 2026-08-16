/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant result == (n - temp_n) / 2;
        loop invariant temp_n + 2 * result == n;
        loop assigns temp_n, result;
        loop variant temp_n;
    */
    while (temp_n > 1)
    {
        //@ assert temp_n > 1;
        temp_n -= 2;
        result += 1;
    }
    
    if (temp_n == 1)
    {
        //@ assert temp_n == 1;
        result += 1;
    }
    
    //@ assert result == (((n) + 1) / 2);
    return result;
}

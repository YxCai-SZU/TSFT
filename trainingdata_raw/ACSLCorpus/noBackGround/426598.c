/*@
    requires 1 <= n <= 100;
    ensures \result >= 0;
    ensures \result == (n / 3) + 1 || \result == n / 3;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    
    result = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant result >= 0;
        loop invariant temp_n == n - 3 * result;
        loop assigns result, temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        result += 1;
        temp_n -= 3;
        //@ assert temp_n == n - 3 * result;
    }
    
    //@ assert temp_n >= 0 && temp_n < 3;
    if (temp_n > 0 && temp_n < 3)
    {
        //@ assert temp_n > 0 && temp_n < 3;
        result += 1;
    }
    
    //@ assert result >= 0;
    //@ assert result == (n / 3) + 1 || result == n / 3;
    return result;
}

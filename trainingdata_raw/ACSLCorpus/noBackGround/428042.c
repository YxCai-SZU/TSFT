/*@
    requires (1 <= (n) <= 100);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int modulo;
    int final_result;
    
    result = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant result == (((n) - (temp_n)) / 2);
        loop invariant n == temp_n + 2 * result;
        loop assigns temp_n, result;
    */
    while (temp_n >= 2)
    {
        temp_n = temp_n - 2;
        result = result + 1;
    }
    
    if (temp_n == 1)
    {
        modulo = 1;
    }
    else
    {
        modulo = 0;
    }
    
    final_result = result + modulo;
    //@ assert final_result == n / 2 + n % 2;
    return final_result;
}

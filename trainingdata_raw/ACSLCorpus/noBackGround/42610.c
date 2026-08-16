/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((((n) / (15))) * 200));
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int temp_n = n;
    const int divisor = 15;
    int result;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= quotient <= n / divisor;
        loop invariant n == temp_n + quotient * divisor;
        loop assigns temp_n, quotient;
        loop variant temp_n;
    */
    while (temp_n >= divisor)
    {
        //@ assert temp_n >= divisor;
        temp_n -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient == ((n) / (divisor));
    result = n * 800 - (quotient * 200);
    //@ assert result == ((n) * 800 - ((quotient) * 200));
    return result;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == (n * 800) - ((n / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int quotient;
    int remainder;
    int divisor;
    int product;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    result = 0;
    temp_n = n;
    
    // Calculate n * 800
    result = n * 800;
    
    // Calculate n / 15
    quotient = 0;
    remainder = 0;
    divisor = 15;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant temp_n == n - quotient * 15;
        loop invariant temp_n >= 0;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= divisor)
    {
        //@ assert temp_n >= 15;
        temp_n -= divisor;
        quotient += 1;
        //@ assert quotient * 15 <= n;
    }
    remainder = temp_n;
    
    // Calculate (n / 15) * 200
    product = quotient * 200;
    
    // Calculate the final result
    result -= product;
    
    //@ assert result == (n * 800) - (quotient * 200);
    //@ assert quotient == n / 15;
    //@ assert result == (n * 800) - ((n / 15) * 200);
    
    return result;
}

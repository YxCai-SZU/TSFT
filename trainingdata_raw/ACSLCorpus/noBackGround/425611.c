/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n * 800) - ((n / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int temp_n = n;
    int divisor = 15;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + divisor * quotient;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= divisor)
    {
        temp_n -= divisor;
        quotient += 1;
    }
    
    //@ assert 0 <= quotient * 200 <= 200 * 100;
    
    int r = (n * 800) - (quotient * 200);
    return r;
}

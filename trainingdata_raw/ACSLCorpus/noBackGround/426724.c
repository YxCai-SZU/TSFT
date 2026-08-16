/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - 200 * (n / 15);
    assigns \nothing;
*/
long func(long n)
{
    long quotient = 0;
    long temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant temp_n == n - 15 * quotient;
        loop invariant temp_n >= 0;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    //@ assert quotient == n / 15;
    //@ assert n * 800 - 200 * quotient == n * 800 - 200 * (n / 15);
    
    return n * 800 - 200 * quotient;
}

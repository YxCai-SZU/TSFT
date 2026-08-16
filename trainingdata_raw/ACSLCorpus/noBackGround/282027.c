/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (n / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int quotient;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    result = 0;
    temp_n = n;
    quotient = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100);
        loop invariant 0 <= quotient <= n / 15;
        loop invariant temp_n == n - quotient * 15;
        loop invariant 0 <= temp_n <= 100;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    //@ assert quotient == n / 15;
    //@ assert 0 <= n * 800 <= 100 * 800;
    //@ assert 0 <= quotient * 200 <= 100 * 200;
    
    result = n * 800 - quotient * 200;
    
    //@ assert result == ((n) * 800 - (n / 15) * 200);
    return result;
}

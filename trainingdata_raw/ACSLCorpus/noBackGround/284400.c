/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n * 800 - (n / 15) * 200);
*/
int func(unsigned long n)
{
    unsigned long x;
    unsigned long quotient;
    unsigned long remainder;
    unsigned long divisor;
    unsigned long y;
    unsigned long ans;
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    divisor = 15;
    
    /*@
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == (n * 800 - (n / 15) * 200);
    
    return (int)ans;
}

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 31415 * r / 10000;
    assigns \nothing;
*/
long func(long r)
{
    long ans;
    long quotient;
    long divisor;
    int is_negative;
    
    //@ assert 2 * 31415 <= 100000;
    
    ans = 2 * 31415 * r;
    quotient = 0;
    divisor = 10000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant ans >= 0;
        loop invariant ans <= 6283000;
        loop invariant (2 * 31415 * (r)) - quotient * divisor == ans;
        loop assigns ans, quotient;
        loop variant ans;
    */
    while (ans >= divisor)
    {
        ans -= divisor;
        quotient += 1;
    }
    
    is_negative = 0;
    if (ans < 0)
    {
        is_negative = 1;
        ans = -ans;
    }
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant ans >= 0;
        loop invariant ans <= 6283000;
        loop assigns ans;
        loop variant ans;
    */
    while (ans >= divisor)
    {
        ans -= divisor;
    }
    
    if (is_negative)
    {
        ans = -ans;
    }
    
    return quotient;
}

int main()
{
    return 0;
}

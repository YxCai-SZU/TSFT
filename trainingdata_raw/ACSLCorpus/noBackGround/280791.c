/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) >= (k));
    ensures \result <= k;
    assigns \nothing;
*/
long func(long a, long b, long c, long k)
{
    long ans;
    long rst;
    
    ans = 0;
    rst = k;
    
    //@ assert (1 <= (a) && (a) <= 1000000000 &&         1 <= (b) && (b) <= 1000000000 &&         1 <= (c) && (c) <= 1000000000 &&         1 <= (k) && (k) <= (a) + (b) + (c) &&         (a) + (b) >= (k));
    
    if (a >= rst)
    {
        ans += rst;
    }
    else
    {
        ans += a;
    }
    
    rst -= a;
    rst -= b;
    
    //@ assert ans <= k;
    
    if (rst < 0)
    {
        ans -= -rst;
    }
    
    //@ assert ans <= k;
    
    return ans;
}

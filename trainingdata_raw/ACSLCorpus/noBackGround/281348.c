/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires 1 <= k && k <= a + b + c;
    requires a + b + c <= 2000000000;
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int k_remaining = k;
    
    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0);
    
    if (a <= k_remaining)
    {
        ans += a;
        k_remaining -= a;
        //@ assert ans == a && k_remaining == k - a;
    }
    else
    {
        //@ assert ans == 0 && k_remaining == k;
        return k;
    }
    
    if (b <= k_remaining)
    {
        k_remaining -= b;
        //@ assert k_remaining == k - a - b;
    }
    else
    {
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }
    
    ans -= k_remaining;
    
    //@ assert ans >= -c;
    
    return ans;
}

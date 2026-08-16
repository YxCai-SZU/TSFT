/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000 && (m) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= n + m - 1;
    assigns \nothing;
*/
long func(long n, long m)
{
    long ans;
    long tmp;

    //@ assert (1 <= (n) && 1 <= (m) && (n) <= 1000000000 && (m) <= 1000000000);
    
    if (n == 1) {
        ans = 0;
    } else {
        ans = n - 2;
    }
    
    tmp = m - 2;
    
    if (tmp < 0) {
        //@ assert ans >= 0;
    } else {
        ans += tmp;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n + m - 1;
    
    return ans;
}

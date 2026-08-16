/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;
    //@ assert 2 <= n <= 100 && 2 <= m <= 100;
    
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    
    //@ assert 1 <= (n - 1) * (m - 1) <= 99 * 99;
    
    if (n > 1 && m > 1) {
        ans = (n - 1) * (m - 1);
    } else {
        ans = 0;
    }
    
    //@ assert ans == (n - 1) * (m - 1);
    return ans;
}

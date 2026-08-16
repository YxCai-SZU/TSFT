/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int func(int n, int k)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert 1 <= k;
    //@ assert k <= n;
    //@ assert n <= 50;
    
    //@ assert ((n) - (k) + 1) <= 50;
    //@ assert ((n) - (k) + 1) >= 1;
    
    result = n - k + 1;
    return result;
}

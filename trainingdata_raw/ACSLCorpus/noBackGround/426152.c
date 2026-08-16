/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    ensures (m > n ==> \result == m - n) && (m <= n ==> \result == 0);
    assigns \nothing;
*/
int func(int n, int m)
{
    int min_val;
    int max_val;
    int res;
    
    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    
    if (m < n) {
        min_val = m;
    } else {
        min_val = n;
    }
    
    if (m > n) {
        max_val = m;
    } else {
        max_val = n;
    }
    
    //@ assert min_val == ((m) < (n) ? (m) : (n));
    //@ assert max_val == ((m) > (n) ? (m) : (n));
    
    if (m > n) {
        //@ assert max_val - min_val == m - n;
        res = max_val - min_val;
    } else {
        //@ assert max_val - min_val == n - m;
        res = 0;
    }
    
    //@ assert (m > n ==> res == m - n) && (m <= n ==> res == 0);
    return res;
}

/*@
    requires 1 <= n && n <= 100;
    requires 0 <= m && m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
int func(int n, int m) {
    int res;
    
    //@ assert n == m ==> n == m;
    
    res = (n == m);
    return res;
}

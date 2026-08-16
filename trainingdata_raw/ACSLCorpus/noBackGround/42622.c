/*@
    requires (1 <= (n) <= 100000 && 1 <= (k) <= (n));
    ensures ((\result) >= 0 && (\result) < (n));
*/
int func(int n, int k) {
    int r;
    
    if (k == 1) {
        r = 0;
    } else {
        r = n - k;
        
        /*@
            loop invariant 1 <= n <= 100000;
            loop invariant 1 <= k <= n;
            loop invariant r >= 0;
            loop invariant r < n;
            loop assigns r;
        */
        while (r >= k) {
            //@ assert r >= k;
            r -= k;
        }
    }
    
    //@ assert r >= 0;
    //@ assert r < n;
    return r;
}

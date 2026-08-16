/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == n - k + 1;
    assigns \nothing;
*/
long func(long n, long k) {
    long result = 0;
    long i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant result == 0;
        loop assigns i;
    */
    while (i < k) {
        i = i + 1;
    }

    //@ assert 0 <= n - k + 1 <= 50;
    result = n - k + 1;
    //@ assert result == n - k + 1;
    
    return result;
}

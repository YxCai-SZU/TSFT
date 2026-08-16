/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == n - k + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k) {
    unsigned int ans = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == ((i) < (k) - 1 ? 0 : (i) - ((k) - 1));
        loop invariant i > 0 ==> ans <= i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        if (i >= k - 1) {
            //@ assert ((i) < (k) - 1 ? 0 : (i) - ((k) - 1)) + 1 == ((i + 1) < (k) - 1 ? 0 : (i + 1) - ((k) - 1));
            ans += 1;
        }
        i += 1;
    }

    //@ assert ans == n - k + 1;
    return ans;
}

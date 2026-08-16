/*@
    requires (1 <= (n) && (n) <= 23);
    ensures \result == (48 - (n));
    assigns \nothing;
*/
int func(int n) {
    int x;
    int result;
    int i;

    x = 48;
    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant result == i;
        loop invariant (1 <= (n) && (n) <= 23);
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n) {
        result += 1;
        i += 1;
    }

    //@ assert result == n;
    return x - result;
}

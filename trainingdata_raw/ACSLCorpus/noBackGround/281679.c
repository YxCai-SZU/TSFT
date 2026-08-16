/*@
    requires (1 <= (n) <= 100 &&
        0 <= (white) <= (n) * (n));
    ensures \result == (((n) * (n)) - (white));
    ensures \result <= n * n;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int white)
{
    unsigned int ans;
    unsigned int i;

    //@ assert white <= n * n;
    //@ assert n <= 100;
    //@ assert n * n <= 10000;

    ans = (n * n) - white;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= white <= n * n;
        loop invariant n * n <= 10000;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    return ans;
}

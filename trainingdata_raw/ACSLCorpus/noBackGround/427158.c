/*@
    requires 2 <= n <= 100;
    requires 2 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    unsigned int ans;

    //@ assert ((n) - 1 >= 1 && (m) - 1 >= 1);
    //@ assert (((n) - 1) * ((m) - 1)) <= (100 - 1) * (100 - 1);

    ans = (n - 1) * (m - 1);
    return ans;
}

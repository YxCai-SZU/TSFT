/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int res;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    res = (n - 1) * (m - 1);
    return res;
}

int main()
{
    return 0;
}

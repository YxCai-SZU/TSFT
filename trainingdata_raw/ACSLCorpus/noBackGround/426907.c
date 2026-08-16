/*@
    requires 1 <= n && n <= 100;
    requires 1 <= m && m <= 100;
    ensures \result == n * m - (n - 1) * m - n * (m - 1) + (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert n * m <= 10000;
    //@ assert (n - 1) * m <= 10000;
    //@ assert n * (m - 1) <= 10000;
    //@ assert (n - 1) * (m - 1) <= 10000;

    result = n * m - (n - 1) * m - n * (m - 1) + (n - 1) * (m - 1);
    return result;
}

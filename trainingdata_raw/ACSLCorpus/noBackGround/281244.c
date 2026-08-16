/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result >= 0;
    ensures ((m) * 2 + 1) * 2 <= n ==> \result == n - ((m) * 2 + 1) * 2;
    ensures ((m) * 2 + 1) * 2 > n ==> \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int x;
    int result;

    x = m * 2 + 1;

    if (x * 2 <= n)
    {
        //@ assert x * 2 <= n;
        result = n - x * 2;
    }
    else
    {
        //@ assert x * 2 > n;
        result = 0;
    }

    return result;
}

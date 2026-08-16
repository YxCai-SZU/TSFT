/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == (n == m);
    assigns \nothing;
*/
int func(int n, int m)
{
    int x;
    int y;
    int result;

    x = 10;
    y = 10;

    //@ assert x == y;

    //@ assert n + x == m + y ==> n == m;

    result = (n + x == m + y);
    return result;
}

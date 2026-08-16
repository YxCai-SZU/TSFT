/*@
    requires 2 <= n <= 100;
    requires 2 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int a;
    int b;
    int result;

    a = n - 1;
    b = m - 1;

    //@ assert (1 <= (a) <= 99);
    //@ assert (1 <= (b) <= 99);
    //@ assert (1 <= (a * b) <= 9801);

    result = a * b;
    return result;
}

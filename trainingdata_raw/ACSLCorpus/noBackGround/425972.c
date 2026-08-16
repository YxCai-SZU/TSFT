/*@
    requires 1 <= n <= 10;
    ensures \result == ((n) * (n) * (n) + 3 * (n) * (n) + 3 * (n) + 1);
    assigns \nothing;
*/
int func(int n)
{
    int result;

    //@ assert (1 <= (n) && (n) <= 10);

    //@ assert n * n <= 100;
    //@ assert 3 * n * n <= 300;
    //@ assert 3 * n <= 30;
    //@ assert n * n * n <= 1000;
    //@ assert ((n) * (n) * (n) + 3 * (n) * (n) + 3 * (n) + 1) <= 1331;

    result = n * n * n + 3 * n * n + 3 * n + 1;

    //@ assert result == ((n) * (n) * (n) + 3 * (n) * (n) + 3 * (n) + 1);
    return result;
}

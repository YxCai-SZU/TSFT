/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
int func(int x)
{
    //@ assert (0 <= (x) <= 1);
    return 1 - x;
}

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int func2(int n, int m)
{
    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    //@ assert n * n <= 10000;
    //@ assert n * n >= m;
    return n * n - m;
}

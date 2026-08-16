/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100 && (m) <= (n));
    ensures \result == ((n) - (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert m <= n;
    return n - m;
}

/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100 && (m) <= (n));
    ensures \result == ((n) - (m));
    assigns \nothing;
*/
int func2(int n, int m)
{
    //@ assert m <= n;
    //@ assert 0 <= n - m <= 100;
    return n - m;
}

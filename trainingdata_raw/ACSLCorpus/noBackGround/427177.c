/*@
    requires (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    ensures \result == ((n) * (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    //@ assert 1 <= n * m && n * m <= 400;
    return n * m;
}

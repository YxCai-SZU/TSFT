/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    //@ assert (1 <= (n) && (n) <= 9);
    //@ assert 1 <= n * n && n * n <= 81;
    //@ assert 1 <= n * n * n && n * n * n <= 729;
    return n * n * n;
}

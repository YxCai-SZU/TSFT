/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == n - k + 1;
    assigns \nothing;
*/
long func(long n, long k)
{
    long result;

    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50);
    result = n - k + 1;
    //@ assert result == n - k + 1;
    return result;
}

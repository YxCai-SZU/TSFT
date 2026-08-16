/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100 && (n) <= (m));
    ensures \result == ((m) - (n));
    ensures \result >= 0;
*/
long func(long n, long m)
{
    long ans;
    //@ assert (0 <= (n) <= 100 && 0 <= (m) <= 100 && (n) <= (m));
    ans = m - n;
    //@ assert ans == ((m) - (n));
    //@ assert ans >= 0;
    return ans;
}

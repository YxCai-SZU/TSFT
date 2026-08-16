/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures \result == (n == m);
*/
int func(long n, long m)
{
    int ans;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ans = (n == m);
    //@ assert ans == (n == m);
    return ans;
}

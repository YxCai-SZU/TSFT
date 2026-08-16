/*@
    requires 1 <= n && n <= 100;
    requires 1 <= m && m <= 100;
    requires 1 <= a && a <= 100;
    ensures \result <==> (((n) - (a)) <= (m) && ((m) - ((n) - (a))) >= 0);
*/
int func(int n, int m, int a)
{
    int result;
    //@ assert (((n) - (a)) <= (m) && ((m) - ((n) - (a))) >= 0) <==> (((n) - (a)) <= (m) && ((m) - ((n) - (a))) >= 0);
    result = ((n - a) <= m) && ((m - (n - a)) >= 0);
    return result;
}

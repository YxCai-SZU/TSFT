/*@
    requires ((((a)) >= 0) && (((b)) >= 0) && (((c)) >= 0) &&
        (((k)) >= 0) && (k) >= 1 && (k) <= (a) + (b) + (c) && (((k)) <= 2000000000));
    ensures \result <= k;
*/
long func(long a, long b, long c, long k)
{
    long ans;
    long rst;
    ans = 0;
    rst = k;

    //@ assert ((rst) >= 0);
    if (a >= rst) {
        ans += rst;
        rst = rst - rst;
    } else {
        ans += a;
        rst = rst - a;
    }

    //@ assert ((rst) >= 0);
    if (b >= rst) {
        rst = rst - rst;
    } else {
        rst = rst - b;
    }

    ans -= rst;

    //@ assert ans <= k;
    return ans;
}

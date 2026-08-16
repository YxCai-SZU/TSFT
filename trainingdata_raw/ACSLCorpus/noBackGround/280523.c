/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
*/
long func(long a, long b, long c, long k)
{
    long cnt;
    long rst;

    cnt = 0;
    rst = k;

    if (a >= rst) {
        cnt += rst;
        rst = 0;
    } else {
        cnt += a;
        rst -= a;
    }

    if (b >= rst) {
        rst = 0;
    } else {
        rst -= b;
    }

    cnt -= rst;

    //@ assert cnt <= k;

    return cnt;
}

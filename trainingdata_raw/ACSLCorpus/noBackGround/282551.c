/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -k;
    ensures \result <= k;
    assigns \nothing;
*/
long func(long a, long b, long c, long k)
{
    long ans;
    long rst;

    ans = 0;
    rst = k;

    if (a >= rst) {
        ans += rst;
        rst -= rst;
    } else {
        ans += a;
        rst -= a;
    }

    if (b >= rst) {
        rst -= rst;
    } else {
        rst -= b;
    }

    ans -= rst;

    //@ assert ans >= -k;

    return ans;
}

/*@
    requires 0 <= a;
    requires 0 <= b;
    requires 0 <= c;
    requires 1 <= k;
    requires k <= a + b + c;
    requires k <= 2000000000;
    ensures \result >= -k;
    ensures \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;
    int use_a;
    int use_b;
    int use_c;

    ans = 0;
    rst = k;

    //@ assert ((a) >= 0) && ((b) >= 0) && ((c) >= 0) && 1 <= k && k <= a + b + c && k <= 2000000000;

    use_a = a < rst ? a : rst;
    ans += use_a;
    rst -= use_a;

    //@ assert use_a == ((a) < (k) ? (a) : (k));

    use_b = b < rst ? b : rst;
    rst -= use_b;

    //@ assert use_b == ((b) < (k - use_a) ? (b) : (k - use_a));

    use_c = c < rst ? c : rst;
    ans -= use_c;

    //@ assert use_c == ((c) < (k - use_a - use_b) ? (c) : (k - use_a - use_b));
    //@ assert ans == use_a - use_c;
    //@ assert ans >= -k;

    return ans;
}

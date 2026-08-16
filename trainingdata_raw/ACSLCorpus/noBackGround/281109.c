/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -c && \result <= a;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int k_remaining = k;

    if (k_remaining <= a) {
        ans += k_remaining;
    } else {
        ans += a;
        k_remaining -= a;
        if (k_remaining > b) {
            ans -= (k_remaining - b);
        }
    }

    //@ assert ans >= -c;
    return ans;
}

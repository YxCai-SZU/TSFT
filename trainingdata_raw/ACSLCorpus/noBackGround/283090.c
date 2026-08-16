/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= 110;
    ensures \result <= 110 + (n - m) * 100 + m * 191;
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans = 0;

    //@ assert 0 <= (n - m) * 100 <= 100 * 100;
    ans += (n - m) * 100;

    //@ assert 0 <= m * 191 <= 5 * 191;
    ans += m * 191;

    //@ assert ans >= 110;
    //@ assert ans <= 110 + (n - m) * 100 + m * 191;

    return ans;
}

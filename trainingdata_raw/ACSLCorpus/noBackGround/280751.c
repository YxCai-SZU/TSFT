/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == ((r) + (100 - (n)) * 10);
    assigns \nothing;
*/
int func(int n, int r)
{
    int ans;
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= r && r <= 4111;
    //@ assert 100 - n >= 0;
    //@ assert (100 - n) * 10 <= 1000;
    ans = r + (100 - n) * 10;
    return ans;
}

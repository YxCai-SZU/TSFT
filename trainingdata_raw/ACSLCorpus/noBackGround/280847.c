/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result >= 0;
    ensures \result == ((r) + ((n) >= 10 ? 0 : 100 * (10 - (n))));
    assigns \nothing;
*/
int func(int n, int r)
{
    int ans;

    //@ assert (1 <= (n) <= 100 && 0 <= (r) <= 4111);

    if (n >= 10) {
        ans = r;
    } else {
        ans = r + 100 * (10 - n);
    }

    //@ assert ans >= 0;
    //@ assert ans == ((r) + ((n) >= 10 ? 0 : 100 * (10 - (n))));

    return ans;
}

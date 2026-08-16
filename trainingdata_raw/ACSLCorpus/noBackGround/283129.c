/*@
    requires (0 <= (x) <= 100 && 0 <= (y) <= 100);
    ensures \result >= 0;
    ensures \result <= x * y;
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int ans;

    //@ assert (0 <= (x) <= 100 && 0 <= (y) <= 100);
    //@ assert 0 <= x * y <= 10000;

    if (x * y < x + y) {
        ans = x * y;
    } else {
        ans = x + y;
    }

    //@ assert ans >= 0;
    //@ assert ans <= x * y;
    return ans;
}

/*@
    requires (400 <= (x) < 2000);
    ensures (1 <= (\result) <= 8);
    assigns \nothing;
*/
int func(int x)
{
    int ans;

    ans = 8;

    if (x < 2000) {
        ans = 8;
    }
    if (x < 1600) {
        ans = 7;
    }
    if (x < 1200) {
        ans = 6;
    }
    if (x < 1000) {
        ans = 5;
    }
    if (x < 800) {
        ans = 4;
    }
    if (x < 600) {
        ans = 3;
    }
    if (x < 400) {
        ans = 2;
    }
    if (x < 200) {
        ans = 1;
    }

    //@ assert ans >= 1;
    //@ assert ans <= 8;

    return ans;
}

/*@
    requires (0 <= (r) && (r) <= 4500 &&
        0 <= (g) && (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int func(int r, int g)
{
    int ans;
    //@ assert (0 <= (r) && (r) <= 4500 &&         0 <= (g) && (g) <= 4500);
    ans = 2 * g - r;
    //@ assert ans == (2 * (g) - (r));
    return ans;
}

/*@
    requires (0 <= (r) && (r) <= 4500 &&
        0 <= (g) && (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int func2(int r, int g)
{
    int ans;
    //@ assert (0 <= (r) && (r) <= 4500 &&         0 <= (g) && (g) <= 4500);
    ans = 2 * g - r;
    //@ assert ans == (2 * (g) - (r));
    return ans;
}

/*@
    requires (2 <= (x) && (x) <= 100) && (2 <= (y) && (y) <= 100);
    ensures \result == ((x) * (y) - ((x) + (y)) + 1);
    assigns \nothing;
*/
int func(int x, int y)
{
    int ans;
    //@ assert 4 <= x * y && x * y <= 10000;
    //@ assert 4 <= x + y && x + y <= 200;
    ans = x * y - (x + y) + 1;
    return ans;
}

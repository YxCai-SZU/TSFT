/*@
    requires (0 <= (x) <= 9);
    requires (0 <= (a) <= 9);
    ensures (((x) < (a) ==> (\result) == 0) && ((x) >= (a) ==> (\result) == 10));
*/
int func(int x, int a)
{
    int ans;
    //@ assert 0 <= x <= 9;
    //@ assert 0 <= a <= 9;
    //@ assert x < a || x >= a;

    if (x < a) {
        ans = 0;
    } else {
        ans = 10;
    }

    //@ assert ans == 0 || ans == 10;
    //@ assert (x < a && ans == 0) || (x >= a && ans == 10);
    return ans;
}

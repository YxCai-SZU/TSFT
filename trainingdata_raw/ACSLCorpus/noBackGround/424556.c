/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == (((b) + (c) - (a) > 0) ? ((b) + (c) - (a)) : 0);
*/
int func(int a, int b, int c)
{
    int plus;
    int ans;

    plus = b + c;
    //@ assert plus == b + c;

    if (plus - a > 0) {
        ans = plus - a;
        //@ assert ans == plus - a;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }

    //@ assert ans == (((b) + (c) - (a) > 0) ? ((b) + (c) - (a)) : 0);
    return ans;
}

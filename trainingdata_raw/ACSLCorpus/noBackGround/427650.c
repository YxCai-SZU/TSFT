/*@
    requires (0 <= (x) && (x) <= 46340 &&
        0 <= (y) && (y) <= 46340);
    ensures \result == x * y;
    ensures \result >= 0;
*/
int func(int x, int y)
{
    //@ assert (0 <= (x) && (x) <= 46340 &&         0 <= (y) && (y) <= 46340);
    int ans = x * y;
    //@ assert ans == x * y;
    //@ assert ans >= 0;
    return ans;
}

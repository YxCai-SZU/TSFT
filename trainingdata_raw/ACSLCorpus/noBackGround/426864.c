/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ensures \result == ((A) - ((B) * 2)) || \result == 0;
    ensures \result >= 0;
*/
int func(int A, int B)
{
    int ans;
    //@ assert (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ans = A - (B * 2);
    //@ assert ans == ((A) - ((B) * 2));
    if (ans < 0)
    {
        ans = 0;
    }
    //@ assert ans == ((A) - ((B) * 2)) || ans == 0;
    //@ assert ans >= 0;
    return ans;
}

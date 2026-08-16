/*@
    requires (1 <= (A) && (A) <= 3) && (1 <= (B) && (B) <= 3);
    requires ((A) != (B));
    assigns \nothing;
    ensures ((\result) == 6 - (A) - (B) &&
        ((\result) == 1 || (\result) == 2 || (\result) == 3) &&
        (\result) != (A) &&
        (\result) != (B));
*/
int func(int A, int B)
{
    int ans;
    //@ assert (1 <= (A) && (A) <= 3) && (1 <= (B) && (B) <= 3);
    //@ assert ((A) != (B));
    ans = 6 - A - B;
    //@ assert ans == (6 - (A) - (B));
    //@ assert ans == 1 || ans == 2 || ans == 3;
    //@ assert ans != A && ans != B;
    return ans;
}

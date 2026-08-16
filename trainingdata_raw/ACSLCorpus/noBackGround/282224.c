/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= ((a) - (b) + (c));
    assigns \nothing;
*/
long func(long a, long b, long c)
{
    long ans;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    ans = c - a + b;
    
    if (ans < 0)
    {
        //@ assert ans < 0;
        ans = 0;
    }
    //@ assert ans >= 0;
    //@ assert ans <= ((a) - (b) + (c));
    return ans;
}

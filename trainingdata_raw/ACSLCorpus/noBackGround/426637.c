/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures 0 <= \result && \result <= x;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int ans = 0;
    int numerator = x - z;
    int denominator = y + z;

    /*@
        loop invariant ((1 <= ((x)) && 1 <= ((y)) && 1 <= ((z)) &&
        ((x)) <= 100000 && ((y)) <= 100000 && ((z)) <= 100000 &&
        ((y)) + ((z)) <= ((x))) &&
        0 <= (numerator) && (numerator) <= (x) &&
        0 <= (ans) && (ans) <= (x) &&
        (ans) <= (x) - (numerator));
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        numerator -= denominator;
        ans += 1;
    }

    //@ assert numerator >= 0;
    //@ assert ans >= 0 && ans <= x;

    return ans;
}

/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result >= 0 && \result <= x;
*/
int func(int x, int y, int z)
{
    int ans = 0;
    int numerator = x - z;
    int denominator = y + z;

    /*@
        loop invariant ((numerator) <= (x) && (numerator) >= 0 &&
        (ans) >= 0 && (ans) <= (x) &&
        (ans) <= (x) - (numerator) &&
        (1 <= ((x)) && 1 <= ((y)) && 1 <= ((z)) &&
        ((x)) <= 100000 && ((y)) <= 100000 && ((z)) <= 100000 &&
        ((y)) + ((z)) <= ((x))));
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert numerator >= denominator;
        numerator -= denominator;
        ans += 1;
        //@ assert ans <= x;
    }

    return ans;
}

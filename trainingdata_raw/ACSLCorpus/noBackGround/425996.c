/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result >= 0 && \result <= x;
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int ans = 0;
    int numerator = x - z;
    int denominator = y + z;

    /*@
        loop invariant 0 <= numerator && numerator <= x;
        loop invariant 0 <= ans && ans <= x;
        loop invariant ans * denominator + numerator == x - z;
        loop invariant (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
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

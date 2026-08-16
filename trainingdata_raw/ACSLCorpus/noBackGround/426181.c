/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures 0 <= \result && \result <= x;
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
        loop invariant ans * denominator == x - z - numerator;
        loop invariant (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert denominator > 0;
        numerator -= denominator;
        ans += 1;
        //@ assert ans <= x;
    }

    return ans;
}

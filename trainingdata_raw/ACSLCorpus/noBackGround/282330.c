/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result >= 0 && \result <= x;
    ensures \result == (((x) - (z)) / ((y) + (z)));
*/
long func(long x, long y, long z)
{
    long ans;
    long numerator;
    long denominator;
    
    ans = 0;
    numerator = x - z;
    denominator = y + z;
    
    /*@
        loop invariant 0 <= numerator && numerator <= x;
        loop invariant 0 <= ans && ans <= x;
        loop invariant ans <= x - numerator;
        loop invariant (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
        loop invariant ans * denominator == (x - z) - numerator;
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert ans <= x;
        numerator -= denominator;
        ans += 1;
    }
    
    return ans;
}

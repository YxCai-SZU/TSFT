/*@
    requires (1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result >= 0;
    ensures \result <= x;
    ensures \result == (((x) - (z)) / ((y) + (z)));
*/
long func(long x, long y, long z) {
    long ans = 0;
    long numerator = x - z;
    long denominator = y + z;

    /*@
        loop invariant 0 <= numerator <= x;
        loop invariant 0 <= ans <= x;
        loop invariant ans * denominator == (x - z) - numerator;
        loop invariant (1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + (z) <= (x));
        loop assigns numerator, ans;
    */
    while (numerator >= denominator) {
        //@ assert ans + 1 <= x;
        numerator -= denominator;
        ans += 1;
    }

    return ans;
}

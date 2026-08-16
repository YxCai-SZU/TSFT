/*@
    requires (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result >= 0;
    ensures \result <= x;
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
        loop invariant ((1 <= ((x)) <= 100000 &&
        1 <= ((y)) <= 100000 &&
        1 <= ((z)) <= 100000 &&
        ((y)) + ((z)) <= ((x))) &&
        (numerator) >= 0 &&
        (numerator) <= (x) &&
        (ans) >= 0 &&
        (ans) <= (x) &&
        (ans) <= (x) - (numerator));
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert ans <= x - numerator;
        numerator -= denominator;
        ans += 1;
    }

    return ans;
}

int main()
{
    return 0;
}

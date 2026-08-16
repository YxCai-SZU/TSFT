/*@
    requires (1 <= (X) <= 100000 &&
        1 <= (Y) <= 100000 &&
        1 <= (Z) <= 100000 &&
        (Y) + 2 * (Z) <= (X));
    ensures \result >= 0 && \result <= X;
    ensures \result == (((X) - (Z)) / ((Y) + (Z)));
    assigns \nothing;
*/
int func(int X, int Y, int Z)
{
    int ans = 0;
    int numerator = X - Z;
    int denominator = Y + Z;

    /*@
        loop invariant 0 <= numerator <= X;
        loop invariant 0 <= ans <= X;
        loop invariant ans * denominator == X - Z - numerator;
        loop invariant numerator >= 0;
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert numerator >= denominator;
        numerator -= denominator;
        ans += 1;
        //@ assert ans * denominator == X - Z - numerator;
    }

    //@ assert ans == (((X) - (Z)) / ((Y) + (Z)));
    return ans;
}

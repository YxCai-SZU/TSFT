/*@
    requires (1 <= (x) <= 100 && 1 <= (y) <= 100 && 1 <= (z) <= 100 && 1 <= (n) <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int x, int y, int z, int n)
{
    int result = 0;
    int numerator = x + y + z;
    int denominator = 1;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 1 <= x <= 100 && 1 <= y <= 100 && 1 <= z <= 100 && 1 <= n <= 100;
        loop invariant numerator >= 0 && numerator <= ((x) + (y) + (z));
        loop invariant denominator >= 1 && denominator <= i + 1;
        loop invariant result >= 0 && result <= i;
        loop invariant i <= 100;
        loop assigns numerator, denominator, result, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert numerator >= 0 && numerator <= ((x) + (y) + (z));
        if (numerator >= denominator)
        {
            numerator -= denominator;
            result += 1;
        }
        else
        {
            break;
        }
        denominator += 1;
        i += 1;
    }
    return result;
}

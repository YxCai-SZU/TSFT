/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x && 1 <= y && 1 <= z &&
        x <= 100000 && y <= 100000 && z <= 100000 &&
        y + z <= x;

    logic integer division_result(integer x, integer y, integer z) =
        (x - z) / (y + z);
*/

/*@
    requires valid_params(x, y, z);
    ensures \result >= 0 && \result <= x;
    ensures \result == division_result(x, y, z);
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int ans;
    int numerator;
    int denominator;

    ans = 0;
    numerator = x - z;
    denominator = y + z;

    /*@
        loop invariant 0 <= numerator && numerator <= x - z;
        loop invariant 0 <= ans && ans <= x;
        loop invariant ans * denominator == x - z - numerator;
        loop invariant denominator == y + z;
        loop assigns numerator, ans;
    */
    while (numerator >= denominator)
    {
        //@ assert ans < x;
        numerator -= denominator;
        ans += 1;
    }

    //@ assert ans * denominator + numerator == x - z;
    //@ assert ans == division_result(x, y, z);
    return ans;
}

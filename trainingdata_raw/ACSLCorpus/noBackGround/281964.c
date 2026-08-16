#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result >= 0 && \result <= x;
*/
int func(int x, int y, int z)
{
    int ans = 0;
    int numerator = x - z;
    int denominator = y + z;

    /*@
        loop invariant ((numerator) <= (x) &&
        (numerator) >= 0 &&
        (ans) >= 0 &&
        (ans) <= (x) &&
        (ans) <= (x) - (numerator) &&
        1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + 2 * (z) <= (x) &&
        (ans) <= (x) - ((numerator) - ((y) + (z))));
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

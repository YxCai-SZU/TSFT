#include <stdbool.h>

/*@
    logic integer max3(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x : ((y >= z) ? y : z);

    lemma max3_bounds:
        \forall integer x, y, z;
            max3(x, y, z) >= x &&
            max3(x, y, z) >= y &&
            max3(x, y, z) >= z &&
            (max3(x, y, z) == x || max3(x, y, z) == y || max3(x, y, z) == z);
*/

/*@
    requires 1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20 && 1 <= d <= 20;
    ensures \result == a + b + c || \result == a + c + d ||
            \result == a + b + d || \result == b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int answers[4];
    int max_val;
    int i;

    answers[0] = a + b + c;
    answers[1] = a + c + d;
    answers[2] = a + b + d;
    answers[3] = b + c + d;

    max_val = answers[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_val == answers[j];
        loop invariant \forall integer k; 0 <= k < i ==> answers[k] <= max_val;
        loop invariant 1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20 && 1 <= d <= 20;
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (answers[i] > max_val)
        {
            max_val = answers[i];
        }
        i++;
    }

    //@ assert max_val == a + b + c || max_val == a + c + d || max_val == a + b + d || max_val == b + c + d;
    return max_val;
}

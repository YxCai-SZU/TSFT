#include <limits.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == (A - B) * 2 || \result == (B - A) * 2;
    ensures \result >= 0;
*/
int func(int A, int B)
{
    int C;
    int D;
    int result;
    int i;

    C = A - B;
    D = B - A;

    if (C >= 0)
    {
        result = 0;
        i = 0;
        /*@
            loop invariant 0 <= i <= C;
            loop invariant result == 2 * i;
            loop invariant C == A - B;
            loop invariant D == B - A;
            loop invariant (1 <= (A) <= 100) && (1 <= (B) <= 100);
            loop assigns result, i;
        */
        while (i < C)
        {
            result += 2;
            i += 1;
        }
        return result;
    }
    else
    {
        result = 0;
        i = 0;
        /*@
            loop invariant 0 <= i <= D;
            loop invariant result == 2 * i;
            loop invariant C == A - B;
            loop invariant D == B - A;
            loop invariant (1 <= (A) <= 100) && (1 <= (B) <= 100);
            loop assigns result, i;
        */
        while (i < D)
        {
            result += 2;
            i += 1;
        }
        return result;
    }
}

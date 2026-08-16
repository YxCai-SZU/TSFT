#include <limits.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    requires -100 <= D <= 100;
    ensures \result == A + B || \result == C + D || \result == A + C || \result == B + D;
*/
int func(int A, int B, int C, int D)
{
    int x1;
    int x2;
    int x3;
    int x4;
    int max_val;

    x1 = A + B;
    x2 = C + D;
    x3 = A + C;
    x4 = B + D;

    max_val = x1;
    if (x2 > max_val)
    {
        max_val = x2;
    }
    if (x3 > max_val)
    {
        max_val = x3;
    }
    if (x4 > max_val)
    {
        max_val = x4;
    }

    //@ assert max_val == x1 || max_val == x2 || max_val == x3 || max_val == x4;

    return max_val;
}

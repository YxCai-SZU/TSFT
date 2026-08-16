#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == (A + B == C || A + C == B || B + C == A);
*/
bool func(int A, int B, int C)
{
    int AB;
    int AC;
    int BC;
    bool ans;

    AB = A + B;
    AC = A + C;
    BC = B + C;
    ans = false;

    //@ assert AB == A + B;
    //@ assert AC == A + C;
    //@ assert BC == B + C;

    if (AB == C)
    {
        ans = true;
    }
    else if (AC == B)
    {
        ans = true;
    }
    else if (BC == A)
    {
        ans = true;
    }

    //@ assert ans == (A + B == C || A + C == B || B + C == A);
    return ans;
}

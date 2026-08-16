#include <stdbool.h>

/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result == true <==> (((A) == (B) && (B) != (C)) ||
        ((B) == (C) && (C) != (A)) ||
        ((C) == (A) && (A) != (B)));
    assigns \nothing;
 */
bool func(int A, int B, int C)
{
    int cnt = 0;

    if (A == B)
    {
        cnt += 1;
    }

    if (B == C)
    {
        cnt += 1;
    }

    if (C == A)
    {
        cnt += 1;
    }

    //@ assert cnt >= 0 && cnt <= 3;

    return cnt == 1;
}

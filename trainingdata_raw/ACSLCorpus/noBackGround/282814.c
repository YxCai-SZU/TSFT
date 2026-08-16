#include <limits.h>

/*@
    requires ((A) > INT_MIN && (A) < INT_MAX) && ((B) > INT_MIN && (B) < INT_MAX) && ((C) > INT_MIN && (C) < INT_MAX);
    ensures \result == 1 <==> (((A) < (B) && (B) < (C)) || ((A) > (B) && (B) > (C)));
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int is_A_equal_to_B;
    int is_B_equal_to_C;
    int is_A_equal_to_C;
    int result;

    //@ assert ((A) > INT_MIN && (A) < INT_MAX) && ((B) > INT_MIN && (B) < INT_MAX) && ((C) > INT_MIN && (C) < INT_MAX);
    is_A_equal_to_B = (A == B) ? 1 : 0;
    is_B_equal_to_C = (B == C) ? 1 : 0;
    is_A_equal_to_C = (A == C) ? 1 : 0;

    if (is_A_equal_to_B || is_B_equal_to_C || is_A_equal_to_C)
    {
        result = 0;
    }
    else
    {
        result = ((A < B && B < C) || (A > B && B > C)) ? 1 : 0;
    }

    //@ assert result == 1 <==> (((A) < (B) && (B) < (C)) || ((A) > (B) && (B) > (C)));
    return result;
}

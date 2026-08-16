#include <stdbool.h>

/*@
    requires 1 <= A && A <= 100;
    requires 1 <= B && B <= 100;
    requires 1 <= C && C <= 100;
    ensures \result == true <==> (A + B == C || B + C == A || C + A == B);
 */
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool is_correct = false;

    //@ assert 1 <= A && A <= 100;
    //@ assert 1 <= B && B <= 100;
    //@ assert 1 <= C && C <= 100;

    if (A + B == C)
    {
        is_correct = true;
    }
    else if (B + C == A)
    {
        is_correct = true;
    }
    else if (C + A == B)
    {
        is_correct = true;
    }

    //@ assert is_correct == true <==> (A + B == C || B + C == A || C + A == B);
    return is_correct;
}

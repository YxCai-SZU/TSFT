#include <stdbool.h>

/*@
    requires 1 <= A && A <= 9;
    requires 1 <= B && B <= 9;
    requires 1 <= C && C <= 9;
    ensures \result == true <==> ((A) < (B) && (B) < (C));
*/
bool func(int A, int B, int C)
{
    bool answer;
    answer = false;

    if (A < B)
    {
        if (B < C)
        {
            answer = true;
        }
        else
        {
            answer = false;
        }
    }
    else
    {
        answer = false;
    }

    //@ assert answer == true <==> ((A) < (B) && (B) < (C));
    return answer;
}

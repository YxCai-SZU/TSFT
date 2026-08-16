#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 5000 &&
        1 <= (B) && (B) <= 5000 &&
        1 <= (C) && (C) <= 10000);
    ensures \result == (A + B >= C);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    int sum;
    bool result;

    //@ assert 1 <= A && A <= 5000;
    //@ assert 1 <= B && B <= 5000;
    //@ assert 1 <= C && C <= 10000;

    sum = A + B;
    result = (sum >= C);

    //@ assert result == (A + B >= C);
    return result;
}

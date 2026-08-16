#include <stdbool.h>

/*@
    requires (0 <= (A) <= 100) && (0 <= (B) <= 100) && (0 <= (C) <= 100);
    ensures \result == (B - A == C - B);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (0 <= (A) <= 100);
    //@ assert (0 <= (B) <= 100);
    //@ assert (0 <= (C) <= 100);

    result = (B - A == C - B);
    return result;
}

int main()
{
    return 0;
}

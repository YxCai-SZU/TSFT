#include <limits.h>

/*@
    requires (INT_MIN < (A) && (A) < INT_MAX);
    requires (INT_MIN < (B) && (B) < INT_MAX);
    requires (INT_MIN < (C) && (C) < INT_MAX);
    ensures \result == (A < B && B < C);
*/
int func(int A, int B, int C)
{
    //@ assert (INT_MIN < (A) && (A) < INT_MAX);
    //@ assert (INT_MIN < (B) && (B) < INT_MAX);
    //@ assert (INT_MIN < (C) && (C) < INT_MAX);
    return (A < B && B < C);
}

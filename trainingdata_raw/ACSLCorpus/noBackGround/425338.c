#include <limits.h>

/*@
    requires ((A) > INT_MIN && (A) < INT_MAX) && ((B) > INT_MIN && (B) < INT_MAX) && ((C) > INT_MIN && (C) < INT_MAX);
    ensures \result == (C >= A && C <= B);
    assigns \nothing;
*/
_Bool func(int A, int B, int C)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert ((A) > INT_MIN && (A) < INT_MAX);
    //@ assert ((B) > INT_MIN && (B) < INT_MAX);
    //@ assert ((C) > INT_MIN && (C) < INT_MAX);

    result = (C >= A && C <= B);
    return result;
}

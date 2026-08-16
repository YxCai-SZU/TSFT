#include <limits.h>
#include <stdbool.h>

/*@
    requires (INT_MIN < (a) < INT_MAX) && (INT_MIN < (b) < INT_MAX) && (INT_MIN < (c) < INT_MAX);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a <= INT_MAX && a >= INT_MIN;
    //@ assert b <= INT_MAX && b >= INT_MIN;
    //@ assert c <= INT_MAX && c >= INT_MIN;

    result = (a < b) && (b < c);
    return result;
}

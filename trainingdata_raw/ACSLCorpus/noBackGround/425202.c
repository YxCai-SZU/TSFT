#include <limits.h>

/*@
    requires ((a) != (b));
    requires (INT_MIN + 1 <= (a) - (b) <= INT_MAX);
    ensures \result == a - b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert ((a) != (b));
    //@ assert (INT_MIN + 1 <= (a) - (b) <= INT_MAX);
    result = a - b;
    //@ assert result == a - b;
    return result;
}

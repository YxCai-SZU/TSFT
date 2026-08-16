#include <stdbool.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int func(int a, int b)
{
    int result;
    //@ assert is_nonnegative(0);
    if (a - 2 * b > 0)
    {
        //@ assert a - 2 * b >= 0;
        result = a - 2 * b;
    }
    else
    {
        result = 0;
    }
    //@ assert is_nonnegative(result);
    return result;
}

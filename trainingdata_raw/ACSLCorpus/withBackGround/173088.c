#include <stdbool.h>

/*@ predicate is_nonnegative(integer x) = x >= 0; */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func(int a, int b)
{
    int result;
    
    result = a - b * 2;
    //@ assert result == a - b * 2;
    
    if (result > 0)
    {
        return result;
    }
    else
    {
        return 0;
    }
}

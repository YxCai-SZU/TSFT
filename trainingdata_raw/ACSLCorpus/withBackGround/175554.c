#include <stdbool.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
*/
int func(int x)
{
    int ans;

    if (x == 0)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }

    return ans;
}

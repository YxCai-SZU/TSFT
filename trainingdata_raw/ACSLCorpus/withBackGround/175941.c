#include <stdbool.h>
#include <stdint.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100000;
    predicate loop_inv(integer x, integer i, integer a) =
        1 <= x <= 100000 &&
        1 <= i <= x + 1 &&
        a >= 0 &&
        a <= i - 1;
*/

/*@
    requires in_range(x);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t a = 0;
    uint32_t i = 1;
    int32_t ans = 0;

    /*@
        loop invariant loop_inv(x, i, a);
        loop assigns a, i;
        loop variant x - i + 1;
    */
    while (i <= x)
    {
        //@ assert 1 <= i <= x + 1;
        if (i >= 1 && i < 10)
        {
            a += 1;
        }
        else if (i >= 100 && i < 1000)
        {
            a += 1;
        }
        else if (i >= 10000 && i < 100000)
        {
            a += 1;
        }
        i += 1;
    }

    if (x == 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }

    //@ assert ans == 0 || ans == 1;
    return ans;
}

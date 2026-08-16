#include <stdint.h>

/*@ predicate condition_holds(integer x) = (x / 100) * 5 >= x; */

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> condition_holds(x);
    ensures \result == 0 ==> !condition_holds(x);
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    uint32_t div_result;
    uint32_t mul_result;

    //@ assert x / 100 <= 50000;
    div_result = x / 100;
    //@ assert div_result * 5 <= 50000;
    mul_result = div_result * 5;

    if (mul_result >= x)
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }
    return ans;
}

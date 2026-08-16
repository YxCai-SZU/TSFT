#include <stdint.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100000;

    logic integer scaled_value(integer x) = (x / 100) * 100 + 100;

    lemma scaled_value_always_greater:
        \forall integer x; is_in_range(x) ==> scaled_value(x) > x;
*/

/*@
    requires is_in_range(x);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (scaled_value(x) == x || scaled_value(x) > x);
    ensures \result == 0 ==> scaled_value(x) != x && scaled_value(x) > x;
*/
int32_t func(uint32_t x)
{
    int32_t ret;
    uint32_t temp;

    //@ assert is_in_range(x);
    temp = (x / 100) * 100 + 100;

    if (temp == x || temp > x)
    {
        ret = 1;
        //@ assert ret == 1;
    }
    else
    {
        //@ assert temp != x && temp > x;
        ret = 0;
        //@ assert ret == 0;
    }

    return ret;
}

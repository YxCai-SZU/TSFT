#include <stddef.h>
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    logic integer base_value(integer x) = (x / 11) * 2;
    logic integer remainder(integer x) = x % 11;
    lemma ans_property:
        \forall integer x;
        valid_range(x) ==>
        (remainder(x) > 6 ==> base_value(x) + 2 >= base_value(x)) &&
        (remainder(x) <= 6 ==> base_value(x) + 1 >= base_value(x));
*/

/*@
    requires valid_range(x);
    ensures \result >= (x / 11) * 2;
    ensures x % 11 > 6 ==> \result == (x / 11) * 2 + 2;
    ensures x % 11 <= 6 ==> \result == (x / 11) * 2 + 1;
*/
size_t func(size_t x)
{
    size_t ans;
    size_t mo;
    ans = (x / 11) * 2;
    mo = x % 11;
    if (mo > 6)
    {
        ans += 2;
        //@ assert mo > 6 ==> ans == (x / 11) * 2 + 2;
    }
    else
    {
        ans += 1;
        //@ assert mo <= 6 ==> ans == (x / 11) * 2 + 1;
    }
    return ans;
}

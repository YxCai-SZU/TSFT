#include <stdint.h>

/*@
    predicate is_valid_s(integer s) = 1 <= s && s <= 100;
    logic integer square(integer s) = s * s;
    lemma square_bounded: \forall integer s; is_valid_s(s) ==> square(s) <= 10000;
*/

/*@
    requires is_valid_s(s);
    ensures \result == square(s);
    assigns \nothing;
*/
uint32_t func(uint32_t s)
{
    uint32_t ans;
    //@ assert is_valid_s(s);
    ans = s;
    if (s != 0)
    {
        //@ assert s > 0 && s <= 100;
        //@ assert s * s <= 10000;
        ans *= s;
    }
    return ans;
}

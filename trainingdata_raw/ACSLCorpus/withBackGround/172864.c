#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a && a <= 100 && 0 <= b && b <= 100;

    logic integer upper_bound(integer a, integer b) = (a * 3) + b;

    lemma ans_bounds:
        \forall integer a, b;
        valid_input(a, b) ==>
        upper_bound(a, b) >= 0;
*/

/*@
    requires valid_input(a, b);
    ensures \result <= upper_bound(a, b);
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;
    //@ assert valid_input(a, b);
    ans = (a * 3) + b;
    //@ assert ans == upper_bound(a, b);
    
    if (ans >= 2)
    {
        ans -= 2;
        //@ assert ans <= upper_bound(a, b);
    }
    else
    {
        //@ assert ans <= upper_bound(a, b);
    }
    
    //@ assert ans >= 0;
    return ans;
}

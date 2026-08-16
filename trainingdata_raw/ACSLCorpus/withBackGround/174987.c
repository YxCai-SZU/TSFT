#include <stdint.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
*/

/*@
    requires bounds(a, b, c);
    ensures \result <= total_sum(a, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans = 0;
    //@ assert bounds(a, b, c);
    
    if (a + b + 1 <= c)
    {
        ans += a + 1;
        uint32_t sub = c - (a + b + 1);
        ans += sub / 2;
        //@ assert ans <= total_sum(a, b, c);
    }
    else
    {
        ans = b + c;
        //@ assert ans <= total_sum(a, b, c);
    }
    
    //@ assert ans <= total_sum(a, b, c);
    return ans;
}

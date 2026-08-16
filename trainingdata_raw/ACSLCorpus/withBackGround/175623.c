#include <stdint.h>

/*@
    predicate a_le_b(integer a, integer b) = 0 <= a <= b <= 1000000000000000000;
    predicate x_valid(integer x) = 1 <= x <= 1000000000000000000;
    
    logic integer floor_div(integer n, integer d) = n / d;
    logic integer floor_mod(integer n, integer d) = n % d;
    
    lemma division_monotonic:
        \forall integer a, b, x;
        a_le_b(a, b) && x_valid(x) ==> floor_div(a, x) <= floor_div(b, x);
*/

/*@
    requires 0 <= a <= b <= 1000000000000000000;
    requires 1 <= x <= 1000000000000000000;
    ensures \result <= (b / x) - (a / x) + 1;
    ensures \result >= (b / x) - (a / x);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    uint64_t ans;
    
    //@ assert a / x <= b / x;
    
    if (a % x == 0)
    {
        ans = (b / x) - (a / x) + 1;
    }
    else
    {
        ans = (b / x) - (a / x);
    }
    
    return ans;
}

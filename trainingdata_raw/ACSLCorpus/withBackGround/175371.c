#include <stdint.h>

/*@
    predicate x_ge_a(integer x, integer a) = x >= a;
    predicate x_lt_a(integer x, integer a) = x < a;
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x >= a ==> \result == 10) && (x < a ==> \result == 0);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t a)
{
    uint32_t ans;
    
    //@ assert 0 <= x <= 9;
    //@ assert 0 <= a <= 9;
    
    if (x >= a) {
        ans = 10;
        //@ assert ans == 10;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert (x >= a && ans == 10) || (x < a && ans == 0);
    return ans;
}

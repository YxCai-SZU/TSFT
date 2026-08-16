#include <stdint.h>

/*@
    predicate a_in_range(integer x) = 1 <= x <= 100000 ==> x / 100 <= 1000;
    predicate b_in_range(integer x) = 1 <= x <= 100000 ==> x % 100 <= 100;
    predicate product_bound(integer x) = 1 <= x <= 100000 ==> (x / 100) * 21 <= 21000;
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t a;
    uint32_t b;
    int32_t result;
    
    //@ assert a_in_range(x);
    //@ assert b_in_range(x);
    //@ assert product_bound(x);
    
    a = x / 100;
    b = x % 100;
    
    if (a * 21 > b) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}

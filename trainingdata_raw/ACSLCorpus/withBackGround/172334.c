#include <stdint.h>

/*@
    predicate a_mod_range(integer a_mod) = 0 <= a_mod <= 2;
    predicate b_mod_range(integer b_mod) = 0 <= b_mod <= 2;
    logic integer mod3(integer x) = x % 3;
    logic integer expected_result(integer a, integer b) = mod3(a) * mod3(b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t a_mod;
    int32_t b_mod;
    int32_t product;
    
    //@ assert a_mod_range(a % 3);
    //@ assert b_mod_range(b % 3);
    
    if (a % 3 == 0) {
        a_mod = 0;
        //@ assert a_mod_range(a_mod);
    } else if (a % 3 == 1) {
        a_mod = 1;
        //@ assert a_mod_range(a_mod);
    } else {
        a_mod = 2;
        //@ assert a_mod_range(a_mod);
    }
    
    if (b % 3 == 0) {
        b_mod = 0;
        //@ assert b_mod_range(b_mod);
    } else if (b % 3 == 1) {
        b_mod = 1;
        //@ assert b_mod_range(b_mod);
    } else {
        b_mod = 2;
        //@ assert b_mod_range(b_mod);
    }
    
    //@ assert a_mod_range(a_mod) && b_mod_range(b_mod);
    product = a_mod * b_mod;
    
    //@ assert product == expected_result(a, b);
    return product;
}

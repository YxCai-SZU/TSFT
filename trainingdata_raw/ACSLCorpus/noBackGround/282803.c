#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) - ((a) / 2) * 2) * ((b) - ((b) / 2) * 2));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_;
    uint32_t b_;
    uint32_t a_odd;
    uint32_t b_odd;
    uint32_t result;
    
    a_ = a / 2;
    b_ = b / 2;
    
    a_odd = a - a_ * 2;
    b_odd = b - b_ * 2;
    
    //@ assert a_odd >= 0 && a_odd <= 1;
    //@ assert b_odd >= 0 && b_odd <= 1;
    //@ assert a_odd * b_odd <= 1;
    
    result = a_odd * b_odd;
    return result;
}

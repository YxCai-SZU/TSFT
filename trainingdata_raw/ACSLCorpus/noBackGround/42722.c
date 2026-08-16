#include <stdint.h>

/*@
    requires (0 < (a) && (a) < 10000 && 0 < (b) && (b) < 10000);
    ensures \result == ((a) * (b) + (b));
    assigns \nothing;
*/
uint32_t non_linear_arith_example4(uint32_t a, uint32_t b)
{
    // Variable declarations at top
    uint32_t result;

    //@ assert (0 < (a) && (a) < 10000 && 0 < (b) && (b) < 10000);
    //@ assert a * b < 10000 * 10000;
    //@ assert a * b + b < 10000 * 10000 + 10000;
    
    result = a * b + b;
    
    //@ assert result == ((a) * (b) + (b));
    return result;
}

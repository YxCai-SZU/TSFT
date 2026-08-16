#include <stdint.h>

/*@
    requires ((1 <= ((X)) <= 100) && (1 <= ((Y)) <= 100) && (((Y)) % 2 == 0));
    ensures \result == ((X) + ((Y) / 2));
    assigns \nothing;
*/
int64_t func(int64_t X, int64_t Y)
{
    // Variable declarations at scope top
    uint64_t Y_unsigned;
    uint64_t half_Y_unsigned;
    int64_t half_Y;
    int64_t result;
    
    //@ assert (1 <= (X) <= 100);
    //@ assert (1 <= (Y) <= 100);
    //@ assert ((Y) % 2 == 0);
    
    // Convert Y to unsigned for division
    if (Y < 0) {
        Y_unsigned = (uint64_t)(-Y);
    } else {
        Y_unsigned = (uint64_t)Y;
    }
    
    half_Y_unsigned = Y_unsigned / 2;
    
    // Convert back to signed
    if (Y < 0) {
        half_Y = -(int64_t)half_Y_unsigned;
    } else {
        half_Y = (int64_t)half_Y_unsigned;
    }
    
    // Add the signed values
    result = X + half_Y;
    
    // Critical verification property
    //@ assert result == ((X) + ((Y) / 2));
    
    return result;
}

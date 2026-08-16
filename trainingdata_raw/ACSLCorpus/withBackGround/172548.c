#include <stdint.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v && v <= 10000;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == 1 || \result == 2 || \result == 3 || \result == 4;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max;
    uint32_t count;
    
    // Find maximum value
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    
    // Count occurrences of maximum
    count = 0;
    //@ assert max >= 1 && max <= 10000;
    
    if (a == max) {
        count += 1;
    }
    if (b == max) {
        count += 1;
    }
    if (c == max) {
        count += 1;
    }
    if (d == max) {
        count += 1;
    }
    
    //@ assert count >= 1 && count <= 4;
    
    if (count == 1) {
        return 1;
    } else if (count == 2) {
        return 2;
    } else if (count == 3) {
        return 3;
    } else {
        return 4;
    }
}

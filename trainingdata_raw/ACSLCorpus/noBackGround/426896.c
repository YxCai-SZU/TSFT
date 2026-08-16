#include <stdint.h>

/*@
    requires ((length) > 0) && ((width) > 0);
    requires ((length) + (width) < 0x40000000);
    requires (2 * (length + width) < 0x80000000);
    ensures \result == 2 * (length + width);
    assigns \nothing;
*/
int32_t rectangle_perimeter(int32_t length, int32_t width) {
    int32_t sum;
    int32_t perimeter;
    
    //@ assert ((length) > 0) && ((width) > 0);
    //@ assert ((length) + (width) < 0x40000000);
    //@ assert (2 * (length + width) < 0x80000000);
    
    sum = length + width;
    
    //@ assert (2 * (sum) < 0x80000000);
    
    perimeter = 2 * sum;
    
    return perimeter;
}

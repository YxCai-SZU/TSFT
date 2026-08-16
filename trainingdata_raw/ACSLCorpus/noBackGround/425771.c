#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9) ==> \result == (int)(a * b);
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t min_value;
    uint32_t max_value;
    
    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    
    if (a < b) {
        min_value = a;
    } else {
        min_value = b;
    }
    
    if (a > b) {
        max_value = a;
    } else {
        max_value = b;
    }
    
    //@ assert min_value == (((a) < (b)) ? (a) : (b));
    //@ assert max_value == (((a) > (b)) ? (a) : (b));
    
    if (max_value <= 9) {
        //@ assert (1 <= (min_value) <= 9) && (1 <= (max_value) <= 9);
        //@ assert min_value * max_value <= 81;
        return (int32_t)(min_value * max_value);
    } else {
        return -1;
    }
}

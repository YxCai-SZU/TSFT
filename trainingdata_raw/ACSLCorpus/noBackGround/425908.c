#include <stdint.h>

/*@ requires \valid_read(xs + (0..3));
    requires (1 <= (xs[0]) <= 1000000000);
    requires (1 <= (xs[1]) <= 1000000000);
    requires (1 <= (xs[2]) <= 1000000000);
    requires (1 <= (xs[3]) <= 1000000000);
    ensures \result == ((xs[0]) * (xs[1])) || 
            \result == ((xs[2]) * (xs[3]));
    ensures \result >= 1;
    assigns \nothing;
 */
int64_t func(const int64_t xs[4])
{
    int64_t max_val;
    int64_t prod1;
    int64_t prod2;
    
    //@ assert 1 <= ((xs[0]) * (xs[1])) <= 1000000000000000000;
    //@ assert 1 <= ((xs[2]) * (xs[3])) <= 1000000000000000000;
    
    prod1 = xs[0] * xs[1];
    prod2 = xs[2] * xs[3];
    
    if (prod1 > prod2) {
        max_val = prod1;
    } else {
        max_val = prod2;
    }
    
    return max_val;
}

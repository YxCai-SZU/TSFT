#include <stdint.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b)) || 
            \result == ((a) - (b)) || 
            \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
*/
int64_t func(int64_t a, int64_t b) {
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t max_val;
    
    x = a + b;
    y = a - b;
    
    //@ assert -10000 <= a * b && a * b <= 10000;
    
    z = a * b;
    
    if (x > y) {
        if (x > z) {
            max_val = x;
        } else {
            max_val = z;
        }
    } else {
        if (y > z) {
            max_val = y;
        } else {
            max_val = z;
        }
    }
    
    return max_val;
}

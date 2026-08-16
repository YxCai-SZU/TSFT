#include <stdint.h>

/*@ requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59) && (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires k >= 0;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2)) - k;
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k) {
    int64_t start_min;
    int64_t end_min;
    int64_t result;

    //@ assert ((h1) * 60 + (m1)) == h1 * 60 + m1;
    //@ assert ((h2) * 60 + (m2)) == h2 * 60 + m2;
    
    start_min = h1 * 60 + m1;
    end_min = h2 * 60 + m2;
    
    //@ assert end_min - start_min == h2 * 60 + m2 - h1 * 60 - m1;
    
    result = end_min - start_min - k;
    return result;
}

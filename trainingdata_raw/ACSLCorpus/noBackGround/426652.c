#include <stdint.h>

/*@ requires (1 <= (k) <= 1000000000 &&
   1 <= (a) <= 1000000000 &&
   1 <= (b) <= 1000000000);
    ensures \result <= k && \result <= a + b;
*/
uint32_t max_circular_track_collisions(uint32_t k, uint32_t a, uint32_t b)
{
    uint32_t min_value;
    uint32_t max_value;
    uint32_t result;
    
    //@ assert (1 <= (k) <= 1000000000 &&    1 <= (a) <= 1000000000 &&    1 <= (b) <= 1000000000);
    
    if (a < b) {
        min_value = a;
    } else {
        min_value = b;
    }
    max_value = a + b - min_value;
    
    //@ assert min_value == ((a < b) ? a : b);
    //@ assert max_value == a + b - min_value;
    
    if (k >= max_value) {
        result = min_value;
    } else if (k >= min_value) {
        result = k;
    } else {
        result = 0;
    }
    
    //@ assert result == (\let min_val = ((a) < (b)) ? (a) : (b);    \let max_val = (a) + (b) - min_val;    ((k) >= max_val) ? min_val : (((k) >= min_val) ? (k) : 0));
    //@ assert result <= k;
    //@ assert result <= a + b;
    
    return result;
}

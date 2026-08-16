#include <stdint.h>

/*@
  requires (1 <= (a) <= 123) && (1 <= (b) <= 123) && (1 <= (c) <= 123) && (1 <= (d) <= 123);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= 1;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t diff;
    uint32_t sum;
    
    if (a > c) {
        diff = a - c;
    } else {
        diff = c - a;
    }
    
    sum = b + d;
    
    if (diff > sum) {
        return -1;
    } else if (diff == sum) {
        return 0;
    } else {
        //@ assert diff < sum;
        return 1;
    }
}

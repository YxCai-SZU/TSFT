#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 20 &&
     1 <= (a) && (a) <= 50 &&
     1 <= (b) && (b) <= 50);
  ensures \result == ((n) * (a)) || \result == b;
  ensures \result <= b;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    //@ assert 1 <= ((n) * (a)) && ((n) * (a)) <= 1000;
    
    int64_t min_val;
    int64_t product = n * a;
    
    if (product < b) {
        min_val = product;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == ((n) * (a)) || min_val == b;
    //@ assert min_val <= b;
    
    return min_val;
}

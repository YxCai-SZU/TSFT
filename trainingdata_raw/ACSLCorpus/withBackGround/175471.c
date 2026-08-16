#include <stdint.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires valid_range(a) && valid_range(b) && valid_range(c);
  ensures \result >= 0;
  assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min1;
    int64_t min2;
    
    //@ assert a + b >= 2;
    //@ assert a + c >= 2;
    //@ assert b + c >= 2;
    
    if (a + b < a + c) {
        min1 = a + b;
    } else {
        min1 = a + c;
    }
    
    //@ assert min1 >= 2;
    
    if (min1 < b + c) {
        min2 = min1;
    } else {
        min2 = b + c;
    }
    
    //@ assert min2 >= 2;
    
    return min2;
}

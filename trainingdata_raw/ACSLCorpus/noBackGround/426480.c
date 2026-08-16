#include <stdint.h>

/*@
  requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1) && ((k) <= (a) + (b) + (c) && (k) <= 2000000000);
  ensures \result <= k;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t result = 0;
    int32_t rest = k;
    
    //@ assert result <= k;
    
    if (a >= rest) {
        result += rest;
        //@ assert result <= k;
        return result;
    } else {
        result += a;
        rest -= a;
    }
    
    //@ assert result <= k;
    
    if (b >= rest) {
        //@ assert result <= k;
        return result;
    } else {
        rest -= b;
        //@ assert result <= k;
        return result;
    }
}

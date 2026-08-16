#include <stdint.h>

/*@
  requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
  ensures \result <= a + b + c;
  ensures \result >= (a + b + 1 <= c ? a + b + 1 + b : b + c);
  assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;
    
    if (a + b + 1 <= c) {
        //@ assert a + b + 1 <= c;
        //@ assert a + b + 1 + b <= a + b + c;
        //@ assert a + b + 1 + b >= a + b + 1;
        result = a + b + 1 + b;
    } else {
        //@ assert b + c <= a + b + c;
        //@ assert b + c >= b;
        result = b + c;
    }
    
    return result;
}

#include <stdint.h>

/*@
  requires ((a) != (b));
  requires ((a) > 0 && (b) > 0);
  requires ((a) <= 3 && (b) <= 3);
  ensures \result > 0;
  ensures \result <= 6;
  ensures \result != a;
  ensures \result != b;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert (6 - (a) - (b)) > 0;
    //@ assert (6 - (a) - (b)) <= 6;
    //@ assert (6 - (a) - (b)) != a;
    //@ assert (6 - (a) - (b)) != b;
    
    result = 6 - a - b;
    return result;
}

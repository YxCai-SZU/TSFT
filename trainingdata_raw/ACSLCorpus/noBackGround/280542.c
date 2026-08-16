#include <stdint.h>

/*@
  requires (1 <= (a) <= 12 && 1 <= (b) <= 31);
  ensures \result == 0 || \result == 1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    //@ assert 1 <= a <= 12;
    //@ assert 1 <= b <= 31;
    
    if (a <= b) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}

#include <stdint.h>

/*@
  requires ((a) >= 0 && (a) <= 100 && (p) >= 0 && (p) <= 100);
  assigns \nothing;
  ensures ((\result) >= 0 && (\result) <= 200);
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t result;
    //@ assert ((a) >= 0 && (a) <= 100 && (p) >= 0 && (p) <= 100);
    
    result = (3 * a + p) / 2;
    
    //@ assert result >= 0;
    //@ assert result <= 200;
    
    return result;
}

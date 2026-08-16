#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (k) && (k) <= 100);
  assigns \nothing;
  ensures ((\result) >= 0 &&
      (\result) <= (n) &&
      ((\result) == 0 || (\result) == 1));
*/
int32_t func(uint32_t n, uint32_t k)
{
    int32_t result = 0;
    
    //@ assert (1 <= (n) && (n) <= 100 &&       1 <= (k) && (k) <= 100);
    
    if (n == 1 && k == 1)
    {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    
    return result;
}

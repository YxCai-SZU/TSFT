#include <stdint.h>

/*@
  requires (1 <= (r) && (r) <= 100);
  ensures \result == 2 * r * 3;
  assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi;
    int32_t result;
    
    //@ assert (1 <= (r) && (r) <= 100);
    
    pi = 3;
    
    //@ assert 2 * r >= 2;
    //@ assert 2 * r <= 200;
    //@ assert 2 * r * pi <= 600;
    
    result = 2 * r * pi;
    
    //@ assert result == 2 * r * 3;
    return result;
}

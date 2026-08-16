#include <stdbool.h>

/*@
  requires x <= 100 && y <= 100;
  ensures \result == (x * y % 2 == 0);
  assigns \nothing;
*/
bool func(unsigned long long x, unsigned long long y)
{
    // Variable declarations at top of scope
    bool result;
    unsigned long long product;
    
    //@ assert x <= 100;
    
    product = x * y;
    //@ assert product <= 100 * 100;
    
    result = (product % 2 == 0);
    //@ assert result == (x * y % 2 == 0);
    
    return result;
}

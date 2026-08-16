#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  ensures \result == (a + b >= 10);
  assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a + b <= 200;
    
    result = (a + b) >= 10;
    
    //@ assert result == (a + b >= 10);
    return result;
}

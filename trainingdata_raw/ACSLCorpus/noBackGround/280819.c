#include <stdbool.h>

/*@
  requires ((a) > 0) && ((b) > 0) && ((c) > 0);
  ensures \result == (a < b && b < c);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((a) > 0);
    //@ assert ((b) > 0);
    //@ assert ((c) > 0);
    
    result = (a < b) && (b < c);
    return result;
}

#include <stdbool.h>

/*@
  requires (1 <= (x) <= 5) && (1 <= (y) <= 5);
  ensures ((\result) == ((x) <= 3 || (y) <= 3));
  assigns \nothing;
*/
bool func(int x, int y)
{
    // Variable declarations at the top
    bool result;
    
    //@ assert 1 <= x && x <= 5;
    //@ assert 1 <= y && y <= 5;
    
    //@ assert x <= 3 || x >= 4;
    //@ assert y <= 3 || y >= 4;
    
    result = (x <= 3) || (y <= 3);
    
    //@ assert ((result) == ((x) <= 3 || (y) <= 3));
    return result;
}

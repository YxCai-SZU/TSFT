#include <stdbool.h>

/*@
  requires (1 <= (n) <= 16 &&
      1 <= (m) <= 16 &&
      (n) + (m) <= 16);
  assigns \nothing;
  ensures \result == true <==> ((n) <= 8 && (m) <= 8);
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;
    
    //@ assert (1 <= (n) <= 16 &&       1 <= (m) <= 16 &&       (n) + (m) <= 16);
    
    if (n <= 8 && m <= 8) {
        result = true;
        //@ assert ((n) <= 8 && (m) <= 8);
    } else {
        //@ assert !((n) <= 8 && (m) <= 8);
        result = false;
    }
    
    return result;
}

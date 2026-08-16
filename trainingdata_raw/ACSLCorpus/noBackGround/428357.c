#include <stdbool.h>

/*@
  requires (1 <= (d) <= 10000 &&
      1 <= (t) <= 10000 &&
      1 <= (s) <= 10000 &&
      (d) <= (t) * (s));
  ensures \result == true;
  assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;
    long product;
    
    // Precondition verification
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    
    // Multiplication bounds verification
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    
    if (d <= product) {
        result = true;
    } else {
        // Unreachable branch due to precondition
        //@ assert false;
        result = false;
    }
    
    // Postcondition verification
    //@ assert result == true;
    
    return result;
}

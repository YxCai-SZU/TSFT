#include <stdbool.h>

/*@
  requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
  ensures \result == (a + b >= c);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    //@ assert (0 <= (c) && (c) <= 100);
    
    result = (a + b >= c);
    return result;
}

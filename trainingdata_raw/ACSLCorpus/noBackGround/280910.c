#include <stdbool.h>

/*@
  requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
  ensures \result == ((a == b && c != a && c != b) || 
                      (b == c && a != b && a != c) || 
                      (a == c && a != b && b != c));
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    if ((a == b && c != a && c != b) || 
        (b == c && a != b && a != c) || 
        (a == c && a != b && b != c)) {
        return true;
    } else {
        return false;
    }
}

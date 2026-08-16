#include <stdbool.h>

/*@
  requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
  ensures \result == ((a == b && b != c) || (b == c && c != a) || (c == a && a != b));
  assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    return (a == b && b != c) || (b == c && c != a) || (c == a && a != b);
}

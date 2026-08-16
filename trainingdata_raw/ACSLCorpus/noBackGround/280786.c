#include <stdbool.h>

/*@
  requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
  requires ((a) != (b) && (a) != (c) && (b) != (c));
  ensures \result == 1 <==> (((a) < (c) && (b) > (c)) || ((a) > (c) && (b) < (c)));
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert ((a) != (b) && (a) != (c) && (b) != (c));
    result = (a < c && b > c) || (a > c && b < c);
    return result;
}

#include <stdbool.h>

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
      ((a) == (c) && (c) != (b)) ||
      ((b) == (c) && (c) != (a)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a)) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> (((a) == (b) && (b) != (c)) ||       ((a) == (c) && (c) != (b)) ||       ((b) == (c) && (c) != (a)));
    return result;
}

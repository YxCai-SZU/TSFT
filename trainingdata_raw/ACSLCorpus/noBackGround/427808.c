#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == 1 <==> (((a) == (b) + 1 && (b) == (c) + 1) ||
      ((a) + 1 == (b) && (b) + 1 == (c)) ||
      ((a) == (b) && (b) == (c) + 1) ||
      ((a) == (b) && (b) + 1 == (c)) ||
      ((a) + 1 == (b) && (b) == (c)) ||
      ((a) == (b) + 1 && (b) == (c)));
*/
bool func(int a, int b, int c) {
    bool is_line = false;
    
    if (a == b + 1 && b == c + 1) {
        is_line = true;
    } else if (a + 1 == b && b + 1 == c) {
        is_line = true;
    } else if (a == b && b == c + 1) {
        is_line = true;
    } else if (a == b && b + 1 == c) {
        is_line = true;
    } else if (a + 1 == b && b == c) {
        is_line = true;
    } else if (a == b + 1 && b == c) {
        is_line = true;
    }
    
    //@ assert is_line == 1 <==> (((a) == (b) + 1 && (b) == (c) + 1) ||       ((a) + 1 == (b) && (b) + 1 == (c)) ||       ((a) == (b) && (b) == (c) + 1) ||       ((a) == (b) && (b) + 1 == (c)) ||       ((a) + 1 == (b) && (b) == (c)) ||       ((a) == (b) + 1 && (b) == (c)));
    
    return is_line;
}

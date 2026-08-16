#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  requires a != b && b != c && a != c;
  ensures \result == 1 <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)) ||
      ((b) < (c) && (c) < (a)) || ((b) > (c) && (c) > (a)) ||
      ((c) < (a) && (a) < (b)) || ((c) > (a) && (a) > (b)));
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool is_between = false;
    
    //@ assert a != b && b != c && a != c;
    
    if (a < b && b < c) {
        is_between = true;
    } else if (a > b && b > c) {
        is_between = true;
    } else if (b < c && c < a) {
        is_between = true;
    } else if (b > c && c > a) {
        is_between = true;
    } else if (c < a && a < b) {
        is_between = true;
    } else if (c > a && a > b) {
        is_between = true;
    }
    
    //@ assert is_between == 1 <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)) ||       ((b) < (c) && (c) < (a)) || ((b) > (c) && (c) > (a)) ||       ((c) < (a) && (a) < (b)) || ((c) > (a) && (a) > (b)));
    return is_between;
}
